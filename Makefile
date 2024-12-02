# g++ -std=c++11 -o main main.cpp Page.cpp WikiLadder.cpp
CXX = g++
CXXFLAGS = -std=c++11

TARGET = main

SRCS = main.cpp Page.cpp WikiLadder.cpp

OBJS = main.o Page.o WikiLadder.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

run:
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
