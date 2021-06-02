#include "catch.hpp"
#include "Deque.hpp"
#include <iostream>

TEST_CASE("Testing the default constructor", "[deque]")
{
  Deque<int> d;

  REQUIRE(d.isEmpty()); //checks if size is 0
}

TEST_CASE("Peak at an empty deque from both the ends", "[deque]")
{
  Deque<float> f;

  REQUIRE_THROWS_AS(f.front(), std::runtime_error);

  REQUIRE_THROWS_AS(f.back(), std::runtime_error);
}

TEST_CASE("Testing the copy constructor", "[deque]")
{
  Deque<int> d0;
  Deque<int> out;

  out.pushFront(0);
  out.pushBack(-1);
  out.pushFront(2);
  out.pushBack(-3);
  out.pushFront(5);
  out.pushFront(6);
  out.pushBack(-7);
  out.pushBack(8);

  Deque<int> d1(out); //calling a copy constructor

  //checks if the last pushed back value to out has been copied appropriately
  REQUIRE(d1.back() == 8);
  //checks if the last pushed front value to out has been copied appropriately
  REQUIRE(d1.front() == 6);
}

TEST_CASE("Testing the growth strategy", "[deque]")
{
  Deque<int> d_64;

  for (int i = 0; i < 32; i++) //pushing 64 values in total
  {
    d_64.pushFront(3 + i);
    d_64.pushBack(-2 + i);
  }

  //64 values have been pushed. Now, we must try to push a value to the front and back.

  d_64.pushFront(0); //pushing an item beyond its previous capacity of 64
  d_64.pushBack(-1);
}

TEST_CASE("Testing the pushBack/popFront -- guessing instructor tests", "[deque]")
{
  //changed the capacity to 2 and tested the following
  Deque<int> d1;
  d1.pushBack(1);
  d1.pushBack(2);

  //attempt to double size and push back

  d1.pushBack(3);
  d1.pushBack(4);

  d1.pushFront(5);
  d1.pushFront(6);
  d1.pushFront(7);

  d1.popFront();
  d1.popFront();
  d1.popFront();
  d1.popFront();

  d1.popFront();
}