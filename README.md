Wiki Ladder Project

Purpose:
The Wiki Ladder Project is a command-line application designed to find a path between two Wikipedia pages by fetching links from each page and constructing a ladder of links. The project utilizes C++, GoogleTest for testing, and libcurl for fetching web pages. The main objective is to explore and demonstrate concepts of graph traversal using the links between Wikipedia articles.

Sources:
For libcurl implementation: 
https://curl.se/libcurl/c/libcurl-tutorial.html

XML and XPath Sources: 
https://www.w3schools.com/xml/xml_xpath.asp
http://www.fifi.org/doc/libxml2-dev/libxml-dev.html/tutorial/ar01s05.html
----------------------------------------------------------

Installation and Setup:

Install linter
-pip install cpplint
-cpplint main.cpp Page.cpp WikiLadder.cpp

Run Program: 
-sudo apt update
-sudo apt install build-essential libcurl4-openssl-dev -libxml2 libxml2-dev
-make
-./WikiLadder

Clean Program:
-make clean

Install Google Test Framework and Run Test:
-git clone https://github.com/google/googletest.git googletest
-cd build
-cmake ..
-make
-./WikiLadderTest


sources: https://proxiesapi.com/articles/scraping-data-from-wikipedia-in-c
https://everything.curl.dev/libcurl/cplusplus.html 
