// Copyright 2024 <Sadie Young and Blaine Seaman>

/**
 * @file Page.cpp
 * @brief Implements the methods for the Page class, which represents a Wikipedia page.
 * 
 * This file includes the implementation of methods for fetching and parsing links from a Wikipedia page,
 * as well as providing access to the page's title and links.
 */

#include "Page.h"
#include <iostream>
#include <vector>
#include <string>
#include <libxml/HTMLparser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include <curl/curl.h>

// Helper function for curl data fetching
/**
 * @brief Callback function for cURL to write fetched content into a string.
 * 
 * This function is called by cURL when it fetches data from a URL. It appends the fetched data to the provided
 * string.
 * 
 * @param contents The data fetched by cURL.
 * @param size The size of each data chunk.
 * @param blockCount The number of data blocks.
 * @param s The string to append the fetched data to.
 * @return The total number of bytes processed.
 */
size_t WriteCallback(void* contents, size_t size, size_t blockCount, std::string* s) {
    size_t totalSize = size * blockCount;
    s->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

// Constructor
/**
 * @brief Constructs a Page object with the specified title.
 * 
 * This constructor initializes the `Page` object with the given title. The `links` member variable is
 * initially empty.
 * 
 * @param title The title of the Wikipedia page.
 */
Page::Page(const std::string& title) : title(title) {}

/**
 * @brief Parses the HTML data to extract links from a Wikipedia page.
 * 
 * This function takes the raw HTML data of a Wikipedia page and uses XPath expressions to extract links
 * to other Wikipedia pages. The links are stored in the `links` member variable. It ensures that the total
 * number of links processed does not exceed 1000.
 * 
 * @param htmlData The raw HTML data of the Wikipedia page.
 */
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
            if (link.find("/wiki/") == 0 && link.find(':') == std::string::npos) {  // Ignore special Wikipedia links
                links.push_back(link.substr(6));  // Remove "/wiki/" prefix
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

/**
 * @brief Fetches the HTML content of the Wikipedia page and parses its links.
 * 
 * This method builds the URL for the Wikipedia page based on its title and uses cURL to fetch the HTML content
 * of the page. Once the content is fetched, it is passed to the `parseLinks` method for extracting links.
 */
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

            parseLinks(htmlData);  // Call parseLinks here
        } else {
            std::cerr << "Failed to fetch URL: " << url << std::endl;
        }
    } else {
        std::cerr << "Failed to initialize CURL" << std::endl;
    }
}

// Getters
/**
 * @brief Gets the title of the Wikipedia page.
 * 
 * This method returns the title of the Wikipedia page.
 * 
 * @return The title of the Wikipedia page.
 */
std::string Page::getTitle() const {
    return title;
}

/**
 * @brief Gets the list of links from the Wikipedia page.
 * 
 * This method returns a vector of strings representing the titles of the pages linked to from the 
 * current Wikipedia page.
 * 
 * @return A vector of strings representing the titles of linked pages.
 */
std::vector<std::string> Page::getLinks() const {
    return links;
}
