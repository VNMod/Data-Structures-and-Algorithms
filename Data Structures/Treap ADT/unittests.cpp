#include "catch.hpp"
#include "treap_bst.hpp"

// Tests if empty() works
// (implicit testing of default constructor)
TEST_CASE("Test Empty Treap", "[TreapBST]")
{
    TreapBST<int, int> t;
    REQUIRE(t.empty() == true);
}

// Tests the copy constructor
// (implicit testing of insert(), search() and height())
TEST_CASE("Testing a variety of methods but mainly copy constructor", "[TreapBST]")
{
    TreapBST<int, std::string> t1;

    t1.insert(7, "j");
    t1.insert(4, "m");
    t1.insert(3, "z");
    t1.insert(11, "a");
    t1.insert(6, "b");

    TreapBST<int, std::string> t2(t1);

    bool found;

    // now, check if all the nodes exist by searching for their keys

    t2.search(7, found);
    REQUIRE(found);

    t2.search(4, found);
    REQUIRE(found);

    t2.search(3, found);
    REQUIRE(found);

    t2.search(11, found);
    REQUIRE(found);

    t2.search(6, found);
    REQUIRE(found);

    REQUIRE(t1.height() == t2.height()); //their heights must be the same

    t2.remove(7);
    t2.search(7, found);
    REQUIRE(!found);

    t2.remove(11);
    t2.search(11, found);
    REQUIRE(!found);

    // Search for a key that does not exist:
    t2.search(12, found);
    REQUIRE(!found);
}

// Tests the assignment operator overloading method
// (implicit testing of insert(), search(), height() and remove())
TEST_CASE("Testing the assignment operator method", "[TreapBST]")
{
    TreapBST<int, std::string> t1;

    t1.insert(5, "l");
    t1.insert(4, "k");
    t1.insert(2, "c");
    t1.insert(11, "d");
    t1.insert(9, "e");

    std::cout << "Height now is: " << t1.height() << std::endl;

    bool found;

    TreapBST<int, std::string> t2 = t1; //operator overloading

    // now, check if all the nodes from t1 exist in t2 by searching for their keys

    t2.search(5, found);
    REQUIRE(found);

    t2.search(4, found);
    REQUIRE(found);

    t2.search(2, found);
    REQUIRE(found);

    t2.search(11, found);
    REQUIRE(found);

    t2.search(9, found);
    REQUIRE(found);

    std::cout << "Height now is: " << t2.height() << std::endl;

    REQUIRE(t1.height() == t2.height());

    t2.remove(9);
    t2.search(9, found);
    REQUIRE(!found);

    t2.remove(4);
    t2.search(4, found);
    REQUIRE(!found);

    std::cout << "Height now is: " << t2.height() << std::endl;
}
