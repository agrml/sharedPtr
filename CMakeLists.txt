cmake_minimum_required(VERSION 3.8)
project(sharedPtr)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O0")

set(SOURCE_FILES sharedPtr.hpp)
#add_executable(sharedPtr ${SOURCE_FILES} tests.cc)


# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(GOOGLE_TESTS_SOURCE_FILES
        ${SOURCE_FILES}
        UnitTests.cc
)
add_executable(GoogleTests ${GOOGLE_TESTS_SOURCE_FILES} UnitTests.cc)
target_link_libraries(GoogleTests
        ${GTEST_LIBRARIES}
        pthread
)