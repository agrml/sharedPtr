cmake_minimum_required(VERSION 3.8)
project(sharedPtr)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O0")

set(SOURCE_FILES sharedPtr.cpp sharedPtr.h)
add_executable(sharedPtr ${SOURCE_FILES})