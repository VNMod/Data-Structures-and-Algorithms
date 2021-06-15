cmake_minimum_required(VERSION 3.5)
project(turing_machine CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE unittests.cpp TuringMachine.hpp)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

# create unittests
add_executable(unittests catch.hpp ${SOURCE})
set_target_properties(unittests PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()

# unit tests
add_test(unittest unittests)

add_custom_target(submission COMMAND
  ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/submission.zip" --format=zip
  TuringMachine.hpp TuringMachine.cpp Tape.hpp Tape.cpp unittests.cpp dNode.txx dLinkedList.txx
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
     
