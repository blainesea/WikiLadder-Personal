#include <libxml/HTMLparser.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include <iostream>

int main() {
    htmlDocPtr doc = htmlReadMemory("<html></html>", 13, nullptr, nullptr, HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);
    if (doc) {
        xmlXPathContextPtr xpathCtx = xmlXPathNewContext(doc);
        if (xpathCtx) {
            std::cout << "XPath context created successfully.\n";
            xmlXPathFreeContext(xpathCtx);
        } else {
            std::cerr << "Failed to create XPath context.\n";
        }
        xmlFreeDoc(doc);
    } else {
        std::cerr << "Failed to parse HTML.\n";
    }
    return 0;
}
