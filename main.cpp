#include "Page.h"
#include "WikiLadder.h"
#include <iostream>

int main() {
    Page start("StartingPage");
    Page target("TargetPage");

    WikiLadder ladderFinder;
    std::vector<std::string> ladder = ladderFinder.findLadder(start, target);

    if (ladder.empty()) {
        std::cout << "No ladder found.\n";
    } else {
        std::cout << "Wiki Ladder:\n";
        for (const std::string& page : ladder) {
            std::cout << page << " -> ";
        }
        std::cout << "END\n";
    }

    return 0;
}
