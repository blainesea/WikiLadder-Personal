#ifndef WIKILADDER_H
#define WIKILADDER_H

#include "Page.h"
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

class WikiLadder {
public:
    // Finds a ladder between the start and target pages
    std::vector<std::string> findLadder(const Page& start, const Page& target);
};

#endif // WIKILADDER_H
