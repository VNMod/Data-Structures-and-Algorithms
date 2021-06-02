cmake_minimum_required(VERSION 3.5)

# require a C++11 compiler for all targets
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

project(detect)

# create unittests
add_executable(detect detect.cpp)
