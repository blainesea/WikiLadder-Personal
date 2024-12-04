#include "Page.h"
#include "WikiLadder.h"
#include <iostream>
#include <string>

int main() {
    std::string startTitle, targetTitle;

    // Prompt user for start and target pages
    std::cout << "Enter the title of the starting Wikipedia page: ";
    std::getline(std::cin, startTitle);
    std::cout << "Enter the title of the target Wikipedia page: ";
    std::getline(std::cin, targetTitle);

    // Create Page objects
    Page start(startTitle);
    Page target(targetTitle);

    // Fetch links from the start page
    std::cout << "Fetching links for the starting page...\n";
    start.fetchLinks();

    // Instantiate WikiLadder and find the ladder
    WikiLadder ladderFinder;
    std::vector<std::string> ladder = ladderFinder.findLadder(start, target);

    // Output the results
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
