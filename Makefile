CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -I/usr/include/libxml2
LIBS = -lxml2 -lcurl
TARGET = WikiLadder
SRC = main.cpp WikiLadder.cpp Page.cpp
OBJ = $(SRC:.cpp=.o)
TEST_LIBS = -lgtest -lgtest_main -pthread

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

test: $(OBJ) test.o
	$(CXX) $(CXXFLAGS) -o test $^ $(LIBS) $(TEST_LIBS)

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run_tests: test
	./test

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
