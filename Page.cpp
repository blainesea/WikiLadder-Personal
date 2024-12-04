#include "Page.h"
#include <iostream>
#include <libxml/HTMLparser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include <curl/curl.h>

// Helper function for curl data fetching
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* s) {
    size_t totalSize = size * nmemb;
    s->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

// Constructor
Page::Page(const std::string& title) : title(title) {}

void Page::parseLinks(const std::string& htmlData) {
    htmlDocPtr doc = htmlReadMemory(htmlData.c_str(), htmlData.size(), nullptr, nullptr, HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);
    if (!doc) {
        std::cerr << "Failed to parse HTML." << std::endl;
        return;
    }

    xmlXPathContextPtr xpathCtx = xmlXPathNewContext(doc);
    if (!xpathCtx) {
        std::cerr << "Failed to create XPath context." << std::endl;
        xmlFreeDoc(doc);
        return;
    }

    xmlXPathObjectPtr xpathObj = xmlXPathEvalExpression(
    reinterpret_cast<const xmlChar*>("//div[@id='mw-content-text']//a[not(@class) or @class='mw-redirect']/@href"),
    xpathCtx
);
    if (!xpathObj || !xpathObj->nodesetval) {
        std::cerr << "Failed to evaluate XPath or no nodes found.\n";
        if (xpathObj) xmlXPathFreeObject(xpathObj);
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return;
    }

    // Check if the number of nodes exceeds the limit
    if (xpathObj->nodesetval->nodeNr > 5000) {
        std::cerr << "XPath returned too many nodes. Stopping processing.\n";
        xmlXPathFreeObject(xpathObj);
        xmlXPathFreeContext(xpathCtx);
        xmlFreeDoc(doc);
        return;
    }

    // Iterate through the nodes and process them
    for (int i = 0; i < xpathObj->nodesetval->nodeNr; ++i) {
        xmlNodePtr node = xpathObj->nodesetval->nodeTab[i];
        if (node && node->type == XML_ATTRIBUTE_NODE) {
            std::string link = reinterpret_cast<const char*>(xmlNodeGetContent(node));
            if (link.find("/wiki/") == 0 && link.find(':') == std::string::npos) { // Ignore special Wikipedia links
                links.push_back(link.substr(6)); // Remove "/wiki/" prefix
                if (links.size() >= 1000) {
                    std::cerr << "Link limit reached. Stopping further processing.\n";
                    break;
                }
            }
        }
    }

    // Clean up
    xmlXPathFreeObject(xpathObj);
    xmlXPathFreeContext(xpathCtx);
    xmlFreeDoc(doc);
}



void Page::fetchLinks() {
    // Build URL
    std::string url = "https://en.wikipedia.org/wiki/" + title;

    // Use cURL to fetch the HTML content
    CURL* curl = curl_easy_init();
    if (curl) {
        std::string htmlData;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &htmlData);
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if (res == CURLE_OK) {
            // Debug output: size of HTML data fetched
            std::cout << "Fetched HTML size: " << htmlData.size() << " bytes\n";

            parseLinks(htmlData); // Call parseLinks here
        } else {
            std::cerr << "Failed to fetch URL: " << url << std::endl;
        }
    } else {
        std::cerr << "Failed to initialize CURL" << std::endl;
    }
}


// Getters
std::string Page::getTitle() const {
    return title;
}

std::vector<std::string> Page::getLinks() const {
    return links;
}
