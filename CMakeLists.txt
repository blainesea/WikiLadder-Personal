cmake_minimum_required(VERSION 3.14)

# Set project name
set(this WikiLadderProject)
project(${this} CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Enable testing
enable_testing()

# Locate libxml2 and libcurl
find_package(LibXml2 REQUIRED)
find_package(CURL REQUIRED)

# Include directories for libxml2 and libcurl
include_directories(${LIBXML2_INCLUDE_DIR})
include_directories(${CURL_INCLUDE_DIRS})

# Include GoogleTest
add_subdirectory(googletest)

# Add headers and sources for your project
set(Headers
    Page.h
    WikiLadder.h
)

set(Sources
    Page.cpp
    WikiLadder.cpp
)

# Add main executable
add_executable(${this} main.cpp ${Sources} ${Headers})

# Link libraries to the main executable
target_link_libraries(${this} PUBLIC ${LIBXML2_LIBRARIES} ${CURL_LIBRARIES})

# Create a library for testing
add_library(${this}_lib STATIC ${Sources} ${Headers})

# Link libraries to the library
target_link_libraries(${this}_lib PUBLIC ${LIBXML2_LIBRARIES} ${CURL_LIBRARIES})

# Add test executable
set(test WikiLadderTest)
set(testSources
    test.cpp
)

add_executable(${test} ${testSources})

# Link the test executable to GoogleTest and your library
target_link_libraries(${test} PUBLIC
    gtest_main
    ${this}_lib
)

# Register the test with CTest
add_test(
    NAME ${test}
    COMMAND ${test}
)
