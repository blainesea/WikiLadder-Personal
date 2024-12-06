/**
 * @file main.cpp
 * @brief Main entry point for the Wiki Ladder application.
 * 
 * This file handles user input and orchestrates the creation of Page and WikiLadder objects to 
 * find and display the Wikipedia ladder between two pages.
 */

#include "Page.h"
#include "WikiLadder.h"
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string startTitle, targetTitle;

    // Prompt user for start and target pages
    /**
     * @brief Asks the user to input the titles of the starting and target Wikipedia pages.
     * 
     * The user is prompted to enter the title of the starting Wikipedia page and the target Wikipedia page.
     */
    std::cout << "Enter the title of the starting Wikipedia page: ";
    std::getline(std::cin, startTitle);
    std::cout << "Enter the title of the target Wikipedia page: ";
    std::getline(std::cin, targetTitle);

    // Create Page objects
    /**
     * @brief Initializes the Page objects for the start and target Wikipedia pages.
     * 
     * The Page objects represent the starting and target Wikipedia pages and are initialized with
     * the titles provided by the user.
     */
    Page start(startTitle);
    Page target(targetTitle);

    // Fetch links from the start page
    /**
     * @brief Fetches the links from the starting Wikipedia page.
     * 
     * This method invokes the `fetchLinks()` function on the start page to retrieve the links
     * from the starting Wikipedia page.
     */
    std::cout << "Fetching links for the starting page...\n";
    start.fetchLinks();

    // Instantiate WikiLadder and find the ladder
    /**
     * @brief Creates a WikiLadder object and attempts to find the ladder between the start and target pages.
     * 
     * The WikiLadder object is used to find a sequence of Wikipedia pages that links the start and target pages.
     */
    WikiLadder ladderFinder;
    std::vector<std::string> ladder = ladderFinder.findLadder(start, target);

    // Output the results
    /**
     * @brief Displays the results of the Wiki Ladder search.
     * 
     * If a ladder is found, the sequence of pages is displayed. If no ladder is found, a message is shown.
     */
    if (ladder.empty()) {
        std::cout << "No ladder found between \"" << startTitle << "\" and \"" << targetTitle << "\".\n";
    } else {
        std::cout << "Wiki Ladder:\n";
        for (size_t i = 0; i < ladder.size(); ++i) {
            std::cout << ladder[i];
            if (i < ladder.size() - 1) std::cout << " -> ";
        }
        std::cout << "\n";
    }

    return 0;
}
