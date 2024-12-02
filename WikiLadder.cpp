#include "WikiLadder.h"
#include <iostream>

// Finds the shortest ladder from start to target using BFS
std::vector<std::string> WikiLadder::findLadder(const Page& start, const Page& target) {
    if (start.getTitle() == target.getTitle()) {
        return {start.getTitle()}; // The ladder is just the single page
    }

    // BFS setup
    std::queue<std::vector<std::string>> toExplore; // Queue of paths
    std::unordered_set<std::string> visited;       // Set of visited pages

    // Initialize with the start page
    toExplore.push({start.getTitle()});
    visited.insert(start.getTitle());

    // BFS loop
    while (!toExplore.empty()) {
        auto currentPath = toExplore.front();
        toExplore.pop();

        // Get the last page in the current path
        std::string currentPageTitle = currentPath.back();
        Page currentPage(currentPageTitle);
        currentPage.fetchLinks();

        // Explore all links from the current page
        for (const std::string& link : currentPage.getLinks()) {
            if (visited.find(link) == visited.end()) { // Skip visited pages
                visited.insert(link);

                // Create a new path
                std::vector<std::string> newPath = currentPath;
                newPath.push_back(link);

                // Check if we've reached the target
                if (link == target.getTitle()) {
                    return newPath; // Found the ladder
                }

                // Otherwise, enqueue the new path for exploration
                toExplore.push(newPath);
            }
        }
    }

    // If no ladder was found
    return {};
}
