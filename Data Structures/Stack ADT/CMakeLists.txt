cmake_minimum_required(VERSION 3.5)
project(P2_1 CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STACK_SOURCE
  Stack.hpp Stack.txx)

set(TEST_SOURCE
  unittests.cpp)

set(SOURCE ${STACK_SOURCE})

# create unittests
add_executable(unittests catch.hpp student_catch.cpp ${SOURCE} ${TEST_SOURCE})

# some simple tests
enable_testing()
add_test(unittests student-tests)

add_custom_target(submission COMMAND
  ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/submission.zip" --format=zip
  Stack.txx unittests.cpp
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
