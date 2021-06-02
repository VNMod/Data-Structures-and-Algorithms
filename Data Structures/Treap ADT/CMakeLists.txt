cmake_minimum_required(VERSION 3.5)
project(treap CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE unittests.cpp treap_bst.hpp)

# create unittests
add_executable(unittests catch.hpp test_catch.cpp ${SOURCE})
set_target_properties(unittests PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()

# unit tests
add_test(unittest unittests)

add_custom_target(submission COMMAND
  ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/submission.zip" --format=zip
  treap_bst.hpp treap_bst.txx unittests.cpp
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
     
