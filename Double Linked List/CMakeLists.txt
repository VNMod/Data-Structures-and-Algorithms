cmake_minimum_required(VERSION 3.5)
project(dlinkedlist CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE unittests.cpp dLinkedList.hpp dNode.hpp)

# create unittests
add_executable(unittests catch.hpp ${SOURCE})
set_target_properties(unittests PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()

# unit tests
add_test(unittest unittests)

add_custom_target(submission COMMAND
  ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/submission.zip" --format=zip
  dNode.txx dLinkedList.txx unittests.cpp
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
     
