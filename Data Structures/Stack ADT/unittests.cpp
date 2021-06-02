// By Varun Nimish Modak for Project 2.1,
// Data Structures and Algorithms, Virginia Tech

#include "catch.hpp"
#include "Stack.hpp"

TEST_CASE("Peak at empty stack", "[Stack]")
{
  Stack<int> s;

  REQUIRE_THROWS_AS(s.peek(), std::range_error);
}

TEST_CASE("Testing the stack constructor, and the size() and isEmpty() methods", "[Stack]")
{
  //declaring an object s of template <int> that should call the default constructor
  Stack<int> s;

  REQUIRE(s.size() == 0); //should indicate that this Stack is empty
  REQUIRE(s.isEmpty());   //should indicate that this Stack is empty
}

TEST_CASE("Testing the copy constructo and peek method", "[Stack]")
{
  Stack<int> A;
  Stack<int> B(A);

  A.push(1);
  A.push(2);
  A.push(3);

  REQUIRE(A.peek() == 3);
}

TEST_CASE("Testing the push() method", "[Stack]")
{
  Stack<int> s;

  int a = 2;

  REQUIRE(s.push(a));
  REQUIRE(s.push(3));
  REQUIRE(s.push(-5));

  // NOW Testing for a growable stack!

  Stack<float> growable;

  for (int i = 0; i <= 200; i++)
  {
    REQUIRE(growable.push(3 + i)); //should return true after passing the capacity of 100
  }
}

TEST_CASE("Testing the pop() method", "[Stack]")
{
  Stack<int> s;

  int a = 2;

  REQUIRE(s.push(a));
  REQUIRE(s.push(3));
  REQUIRE(s.push(-5));

  s.pop();

  REQUIRE(s.size() == 2);
  REQUIRE(s.peek() == 3);

  s.pop();

  REQUIRE(s.size() == 1);
  REQUIRE(s.peek() == a);

  s.pop();

  REQUIRE(s.isEmpty());

  //s.peek(); -> This should return an exception in the console window
}

TEST_CASE("Testing the clear() method", "[Stack]")
{
  Stack<int> s;

  int a = 2;

  for (int i = 0; i <= 25; i++)
  {
    REQUIRE(s.push(3 + i));
  }

  s.clear();

  REQUIRE(s.isEmpty()); //testing if clear() emptied the stack
}