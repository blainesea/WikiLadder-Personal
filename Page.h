/**
 * @file Page.h
 * @brief Defines the Page class, which represents a Wikipedia page and its links.
 * 
 * This file contains the declaration of the Page class, which models a Wikipedia page. Each Page object 
 * stores the title of the page and a list of links to other pages. The class also includes methods to 
 * fetch links from a Wikipedia page and access the page's title and links.
 */

#ifndef PAGE_H
#define PAGE_H

#include <string>
#include <vector>

/**
 * @class Page
 * @brief Represents a Wikipedia page with a title and a list of links to other pages.
 * 
 * The Page class models a single Wikipedia page, including its title and the hyperlinks to other pages 
 * contained within the page. It includes methods to fetch links from the page and retrieve the title and 
 * list of links.
 */
class Page {
private:
    std::string title; ///< The title of the Wikipedia page.
    std::vector<std::string> links; ///< A list of links found on the Wikipedia page.

    /**
     * @brief Parses the HTML data of the page to extract the links.
     * 
     * This private method processes the HTML data of the page to identify and extract hyperlinks.
     * It stores the links in the `links` member variable.
     * 
     * @param htmlData The raw HTML data of the page from which to extract links.
     */
    void parseLinks(const std::string& htmlData);

public:
    /**
     * @brief Constructs a Page object with the specified title.
     * 
     * This constructor initializes a Page object with the given title. The `links` member variable 
     * is initially empty and will be populated when the `fetchLinks` method is called.
     * 
     * @param title The title of the Wikipedia page.
     */
    Page(const std::string& title);

    /**
     * @brief Fetches links from the Wikipedia page.
     * 
     * This method fetches the HTML content of the page and parses it to extract all links to other pages. 
     * The links are stored in the `links` member variable.
     */
    void fetchLinks();

    /**
     * @brief Gets the title of the Wikipedia page.
     * 
     * This method returns the title of the page.
     * 
     * @return The title of the Wikipedia page.
     */
    std::string getTitle() const;

    /**
     * @brief Gets the list of links from the Wikipedia page.
     * 
     * This method returns a vector of strings representing the titles of the pages linked to from the 
     * current Wikipedia page.
     * 
     * @return A vector of strings representing the titles of linked pages.
     */
    std::vector<std::string> getLinks() const;
};

#endif // PAGE_H
