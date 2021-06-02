cmake_minimum_required(VERSION 3.5)
project(P2_1 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(DEQUE_SOURCE
  Deque.hpp Deque.txx)

set(TEST_SOURCE
  unittests.cpp)

set(SOURCE ${DEQUE_SOURCE})

# create unittests
add_executable(unittests catch.hpp test_catch.cpp ${SOURCE} ${TEST_SOURCE})

# some simple tests
enable_testing()
add_test(unittests unittests)

add_custom_target(submission COMMAND
  ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/submission.zip" --format=zip
  Deque.hpp Deque.txx unittests.cpp
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
