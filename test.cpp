#include "WikiLadder.h"
#include "Page.h"       
#include <gtest/gtest.h>


TEST(WikiLadderTest, ConnectedTest1) {
    WikiLadder wikiLadder;
    Page start("Pizza");
    Page target("Tomatoes");
    std::vector<std::string> result = wikiLadder.findLadder(start, target);
    std::vector<std::string> expected = {"Pizza", "Lahmacun", "Tomatoes"};
    ASSERT_EQ(result, expected);
}

TEST(WikiLadderTest, WrongExpected) {
    WikiLadder wikiLadder;
    Page start("Pizza");
    Page target("Tomatoes");
    std::vector<std::string> result = wikiLadder.findLadder(start, target);
    std::vector<std::string> expected = {"Pizza", "Peanut", "Tomatoes"};
    ASSERT_NE(result, expected);
}

TEST(WikiLadderTest, RandomAssociation1) {
    WikiLadder wikiLadder;
    Page start("Football");
    Page target("Europe");
    std::vector<std::string> result = wikiLadder.findLadder(start, target);
    std::vector<std::string> expected = {"Football", "Association_football", "Europe"};
    ASSERT_EQ(result, expected);
}

TEST(WikiLadderTest, LessConnectedTest1) {
    WikiLadder wikiLadder;
    Page start("Dog");
    Page target("Symbiosis");
    std::vector<std::string> result = wikiLadder.findLadder(start, target);
    std::vector<std::string> expected = {"Dog", "Mammal", "Symbiosis"};
    ASSERT_EQ(result, expected);
}

TEST(WikiLadderTest, ConnectedTest2) {
    WikiLadder wikiLadder;
    Page start("Dog");
    Page target("Commensalism");
    std::vector<std::string> result = wikiLadder.findLadder(start, target);
    std::vector<std::string> expected = {"Dog", "Commensalism"};
    ASSERT_EQ(result, expected);
}

TEST(WikiLadderTest, sameInput) {
    WikiLadder wikiLadder;
    Page start("dog");
    Page target("dog");
    std::vector<std::string> result = wikiLadder.findLadder(start, target);
    std::vector<std::string> expected = {"dog"};
    ASSERT_EQ(result, expected);
}

TEST(WikiLadderTest, EmptyStart) {
    WikiLadder wikiLadder;
    Page start("");
    Page target("Pizza");
    std::vector<std::string> result = wikiLadder.findLadder(start, target);
    ASSERT_TRUE(result.empty()); 
}

TEST(WikiLadderTest, CompletelyEmpty) {
    WikiLadder wikiLadder;
    Page start("");
    Page target("");
    std::vector<std::string> result = wikiLadder.findLadder(start, target);
    ASSERT_TRUE(result.empty() || result.size() == 1);  
}

TEST(WikiLadderTest, CaseSensitivity) {
    WikiLadder wikiLadder;
    Page start("dog");
    Page target("Dog");
    std::vector<std::string> result = wikiLadder.findLadder(start, target);
    std::vector<std::string> expected = {"dog"};
    ASSERT_NE(result, expected);
}

TEST(WikiLadderTest, LowercaseCPlusPlusFails) {
    WikiLadder wikiLadder;
    Page start("c++");
    Page target("Science");  
    std::vector<std::string> result = wikiLadder.findLadder(start, target);
    ASSERT_TRUE(result.empty()) << "Expected no ladder found between 'c++' and 'Science' due to case sensitivity.";
}

TEST(WikiLadderTest, ProveUppercase) {
    WikiLadder wikiLadder;
    Page start("C++");
    Page target("Science");
    std::vector<std::string> result = wikiLadder.findLadder(start, target);
    std::vector<std::string> expected = {"C++", "MATLAB", "Science"};
    ASSERT_EQ(result, expected);

}

TEST(WikiLadderTest, DoubleWordInput) {
    WikiLadder wikiLadder;
    Page startWithUnderscores("New_York");
    Page targetWithUnderscores("Big_Apple");
    std::vector<std::string> resultWithUnderscores = wikiLadder.findLadder(startWithUnderscores, targetWithUnderscores);
    std::vector<std::string> expectedWithUnderscores = {"New_York", "New_York_Harbor", "Big_Apple"};
    ASSERT_EQ(resultWithUnderscores, expectedWithUnderscores);

}
TEST(WikiLadderTest, NoSpaces) {
    WikiLadder wikiLadder;
    Page start("New York");
    Page target("Big Apple");
    std::vector<std::string> result = wikiLadder.findLadder(start, target);
    ASSERT_TRUE(result.empty());
}

TEST(WikiLadderTest, SingleLetter) {
    WikiLadder wikiLadder;
    Page start("A");
    Page target("B");
    std::vector<std::string> result = wikiLadder.findLadder(start, target);
    std::vector<std::string> expected = {"A", "B"};

    ASSERT_EQ(result, expected);
}

TEST(WikiLadderTest, SpecialCharacters) {
    WikiLadder wikiLadder;
    Page start("Multi-pack");
    Page target("Shrink_wrap");
    std::vector<std::string> result = wikiLadder.findLadder(start, target);
    std::vector<std::string> expected = {"Multi-pack", "Shrink_wrap"};
    ASSERT_EQ(result, expected);
}

TEST(WikiLadderTest, Numerals) {
    WikiLadder wikiLadder;
    Page start("1");
    Page target("10");
    std::vector<std::string> result = wikiLadder.findLadder(start, target);
    std::vector<std::string> expected = {"1", "10"};
    ASSERT_EQ(result, expected);
}
