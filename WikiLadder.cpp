// Copyright 2024 Sadie Young and Blaine Seaman

/**
 * @file WikiLadder.cpp
 * @brief Contains the implementation of the WikiLadder class.
 * 
 * This file implements the logic to find the shortest "wiki ladder" 
 * between two Wikipedia pages using a breadth-first search (BFS) algorithm.
 */
#include "WikiLadder.h"
#include <iostream>
#include <queue>
#include <unordered_set>
#include <string>
#include <vector>
/**
 * @brief Finds the shortest ladder of Wikipedia pages from the start page to the target page.
 * 
 * This function uses a breadth-first search (BFS) algorithm to explore links from the 
 * start page and find the shortest path to the target page. It constructs a path (ladder) 
 * that consists of Wikipedia pages, where each page is linked to the next in the ladder.
 * 
 * @param start The starting page (from which to begin searching).
 * @param target The target page (the goal of the search).
 * @return A vector of strings representing the ladder of page titles from start to target.
 *         If no path is found, an empty vector is returned.
 * 
 * @note If the start and target pages are the same, the ladder will contain just that page.
 */
std::vector<std::string> WikiLadder::findLadder(const Page& start, const Page& target) {
    if (start.getTitle() == target.getTitle()) {
        return {start.getTitle()};  // The ladder is just the single page
    }

    // BFS setup
    std::queue<std::vector<std::string>> toExplore;  // Queue of paths
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
            if (visited.find(link) == visited.end()) {  // Skip visited pages
                visited.insert(link);

                // Create a new path
                std::vector<std::string> newPath = currentPath;
                newPath.push_back(link);

                // Check if we've reached the target
                if (link == target.getTitle()) {
                    return newPath;  // Found the ladder
                }

                // Otherwise, enqueue the new path for exploration
                toExplore.push(newPath);
            }
        }
    }

    // If no ladder was found
    return {};
}
