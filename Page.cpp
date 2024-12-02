#include "Page.h"
#include <iostream>

Page::Page(const std::string& title) : title(title) {}

const std::string& Page::getTitle() const {
    return title;
}

const std::vector<std::string>& Page::getLinks() const {
    return links;
}

void Page::fetchLinks() {
//Mock
    if (title == "StartingPage") {
        links = {"Page1", "Page2", "Page3"};
    } else if (title == "Page1") {
        links = {"Page4", "TargetPage"};
    } else if (title == "Page2") {
        links = {"Page5"};
    } else if (title == "Page3") {
        links = {"Page6"};
    } else if (title == "Page4") {
        links = {"TargetPage"};
    } else {
        links = {}; 
    }
}
