/**
 * @file WikiLadder.h
 * @brief Defines the WikiLadder class, which finds the shortest ladder of Wikipedia pages.
 * 
 * This file contains the declaration of the WikiLadder class, which is responsible for finding 
 * the shortest path (ladder) between two Wikipedia pages using a breadth-first search (BFS) algorithm.
 * The class uses the Page class to represent individual Wikipedia pages and their links.
 */

#ifndef WIKILADDER_H
#define WIKILADDER_H

#include "Page.h"
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

/**
 * @class WikiLadder
 * @brief A class that finds the shortest ladder of Wikipedia pages between a start and target page.
 * 
 * The WikiLadder class uses a breadth-first search (BFS) algorithm to find the shortest sequence 
 * of Wikipedia pages that connect a start page to a target page. Each page in the ladder contains 
 * a hyperlink to the next page in the sequence.
 */
class WikiLadder {
public:
    /**
     * @brief Finds the shortest ladder between the start and target pages.
     * 
     * This function uses a breadth-first search (BFS) to find the shortest path (ladder) from the 
     * start page to the target page by exploring links from each page in the path. The function 
     * returns a vector of strings representing the sequence of page titles from start to target.
     * 
     * @param start The starting page from which to begin searching.
     * @param target The target page to find a path to.
     * @return A vector of strings representing the ladder of page titles from start to target. 
     *         If no path is found, an empty vector is returned.
     */
    std::vector<std::string> findLadder(const Page& start, const Page& target);
};

#endif // WIKILADDER_H
