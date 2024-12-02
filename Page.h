#ifndef PAGE_H
#define PAGE_H

#include <string>
#include <vector>

class Page {
private:
    std::string title;                 // Title of the Wikipedia page
    std::vector<std::string> links;    // Links to other pages

public:
    // Constructor
    Page(const std::string& title);

    // Accessor for the page title
    const std::string& getTitle() const;

    // Accessor for the links
    const std::vector<std::string>& getLinks() const;

    // Fetch links for the page (mock implementation for now)
    void fetchLinks();
};

#endif // PAGE_H
