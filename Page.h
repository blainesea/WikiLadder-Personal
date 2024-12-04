#ifndef PAGE_H
#define PAGE_H

#include <string>
#include <vector>

class Page {
private:
    std::string title;
    std::vector<std::string> links;

    void parseLinks(const std::string& htmlData);

public:
    Page(const std::string& title);

    // Fetch links from the page
    void fetchLinks();

    // Getters
    std::string getTitle() const;
    std::vector<std::string> getLinks() const;
};

#endif // PAGE_H
