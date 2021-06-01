// By Varun Nimish Modak for Project 1.1,
// Data Structures and Algorithms, Virginia Tech

#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE
#include "catch.hpp"
#include "dNode.hpp"
#include "dLinkedList.hpp"

// **************************************************** //
// Testing each of dNode's methods and constructors:

// 1. Testing the default constructor and the getItem(), getPrev() and getNext() methods
TEST_CASE("Test default constructor for dNode and the getItem(), getPrev() and getNext() methods", "[dNode]")
{
    dNode<int> node1;
    REQUIRE(node1.getItem() == 0);
    REQUIRE(node1.getPrev() == nullptr);
    REQUIRE(node1.getNext() == nullptr);
}

// 2. Testing the paramterized constructor for appropriately passing parameters and setting items at the declaration of a dNode object
TEST_CASE("Test parameterized constructor for dNode", "[dNode]")
{
    float item = 2.5;
    dNode<float> node1(item);
    REQUIRE(node1.getItem() == 2.5);
}

// 3. Testing the setItem method for the dNode method
TEST_CASE("Test setItem method for dNode", "[dNode]")
{
    double item = -3.4;
    dNode<double> node;
    node.setItem(item);
    REQUIRE(node.getItem() == -3.4);
}

// 4. Testing the setNext method for the dNode method
TEST_CASE("Test setNext method for dNode", "[dNode]")
{
    dNode<int> node;
    dNode<int> *next = nullptr;
    node.setNext(next);
    REQUIRE(node.getNext() == next);
}

// 5. Testing the setPrev method for the dNode method
TEST_CASE("Test setPrev method for dNode", "[dNode]")
{
    dNode<int> node;
    dNode<int> *prev = nullptr;
    node.setNext(prev);
    REQUIRE(node.getPrev() == prev);
}

// **************************************************** //
// Tests for dLinkedList's methods and constructors:

// 6. Testing the default constructor and getCurrentSize() method
TEST_CASE("Test the default constructor for the dLinkedList, the getCurrentSize() and isEmpty() method", "[dLinkedList]")
{
    dLinkedList<int> list;
    REQUIRE(list.getCurrentSize() == 0); //checks if the default size of the list has been set to 0
    REQUIRE(list.isEmpty());             //checks if the list is empty be default
    REQUIRE(list.getHead() == nullptr);  //checks if the pointers have been set to NULL
    REQUIRE(list.getTail() == nullptr);  //checks if the pointers have been set to NULL
}

// **************************************************** //
// Testing each of dLinkedList's methods and constructors:

// 7. Testing the add() method
TEST_CASE("Test the add() method for the dLinkedList", "[dLinkedList]")
{
    dLinkedList<float> list;
    float a[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        list.add(a[i]);
    }

    //Note: now, the list contains 5, 4, 3, 2, 1

    for (int i = 5, j = 0; j < 5; i--, j++)
    {
        REQUIRE(list.getItem(j) == a[i - 1]); //checks if the added item are at their respective index
    }
}

// 8. Testing the remove() method
TEST_CASE("Test the remove() method for the dLinkedList", "[dLinkedList]")
{
    dLinkedList<float> list;
    float a = 2.5;
    float b = -3.5;
    float c = 4.5;
    list.add(a);
    list.add(b);
    list.add(c);
    REQUIRE(list.getCurrentSize() == 3);
    list.remove(c);
    REQUIRE(list.getCurrentSize() == 2); //checks the number of items or size of the list
    REQUIRE(!list.contains(c));          //checks if the removed item is still in the list
    REQUIRE(list.contains(b));           //checks if the other elements are still present and unaffected
    REQUIRE(list.contains(a));           //checks if the other elements are srtill present and unaffected

    list.remove(a);
    list.remove(b);
    REQUIRE(list.isEmpty());         //checks if the list is empty
    REQUIRE_FALSE(list.remove(3.5)); //checks to see that you cannot remove an item that does not exist
}

// 9. Testing the contains() method
TEST_CASE("Test the contains() method for the dLinkedList", "[dLinkedList]")
{
    dLinkedList<float> list;
    float a[10] = {1, 2, -3, 4.67, 7.5, 8.913, 3.14, -5.2, 1.1, 10};

    for (int i = 0; i < 10; i++)
    {
        list.add(a[i]);
    }

    for (int i = 0; i < 10; i++) //checks to see if all the added elements are contained within the list
    {
        REQUIRE(list.contains(a[i]));
    }
}

// 10. Testing the getFrequencyOf() method
TEST_CASE("Test the getFrequencyOf() method for the dLinkedList", "[dLinkedList]")
{
    dLinkedList<float> list;
    float a[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    float b[3] = {-1, 2, 1.1};
    float c[5] = {2.2, 2.2, -2.2, 3.2, 3.2};
    for (int i = 0; i < 10; i++)
    {
        list.add(a[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        list.add(b[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        list.add(c[i]);
    }

    //checking the frequency of each repeating and non-repeating item
    REQUIRE(list.getFrequencyOf(1) == 10);
    REQUIRE(list.getFrequencyOf(-1) == 1);
    REQUIRE(list.getFrequencyOf(1.1) == 1);
    REQUIRE(list.getFrequencyOf(2.2) == 2);
    REQUIRE(list.getFrequencyOf(3.2) == 2);
    REQUIRE(list.getFrequencyOf(-2.2) == 1);
}

// 11. Testing the clear() method
TEST_CASE("Test the clear() method for the dLinkedList", "[dLinkedList]")
{
    dLinkedList<float> list;
    float a[10] = {1.76, -2.2, 0, 1.99, 1.748, 2.1, -1.9, 1.67, 1.32, 1.4};
    for (int i = 0; i < 10; i++)
    {
        list.add(a[i]);
    }

    list.clear(); //clears the whole list

    REQUIRE(list.isEmpty()); //to check if the bag is empty

    for (int i = 0; i < 10; i++)
    {
        REQUIRE(!list.contains(a[i])); //checking to see if all the items don't exist anymore
    }

    REQUIRE(list.getCurrentSize() == 0); //to check if the itemCount decrements properly to 0
}

// 12. Testing the insertAt() and getIndex() method
TEST_CASE("Test the insertAt() and getIndex() method for the dLinkedList", "[dLinkedList]")
{
    dLinkedList<float> list;
    float a[5] = {1, 2, 3, 4, 5};
    float b = 6;

    for (int i = 0; i < 5; i++)
    {
        list.add(a[i]);
    }

    //Note: now, the list contains 5, 4, 3, 2, 1

    list.insertAt(b, 4);

    REQUIRE(list.contains(b));
    REQUIRE(list.getIndex(b) == 4);

    dLinkedList<float> list2;
    for (int i = 0; i < 5; i++)
    {
        list2.insertAt(a[i], i);
    }

    for (int i = 0; i < 5; i++)
    {
        REQUIRE(list2.getItem(i) == a[i]); //checks if all the items have been appropriatelly added
    }

    REQUIRE_FALSE(list2.insertAt(5, -1)); //index -1 does not exist, so this should return false

    list2.insertAt(9, 8); //although the index provided here is 8, it should be added at the back of the list and thus index 5

    REQUIRE(list2.getIndex(9) == 5); //verifies the above insertAt()
}

// 13. Testing the removeAt() method
TEST_CASE("Test the removeAt() method for the dLinkedList", "[dLinkedList]")
{
    dLinkedList<float> list;
    float a[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        list.add(a[i]);
    }

    // Note: now, the list contains 5, 4, 3, 2, 1

    list.removeAt(3);

    REQUIRE(!list.contains(2));

    // Note: now, the list should contain 5, 4, 3, 1 -- tested a removal from the middle of the list

    list.removeAt(2);

    REQUIRE(!list.contains(3));

    // Note: now, the list should contain 5, 4, 1 -- tested another removal from the middle of the list

    list.removeAt(0);

    REQUIRE(!list.contains(5));

    // Note: now, the list should contain 4, 1 -- tested a removal from the beginning of the list

    list.removeAt(1);

    REQUIRE(!list.contains(1));

    // Note: now, the list should contain 4 -- tested a removal from the end of the list

    list.removeAt(0);

    // Note: the list should now be empty

    REQUIRE(!list.contains(4));
    REQUIRE(list.getCurrentSize() == 0);
}

// 14. Testing the replace() method
TEST_CASE("Test the replace() method for the dLinkedList", "[dLinkedList]")
{
    dLinkedList<float> list;
    float a[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        list.add(a[i]);
    }

    // Note: now, the list contains 5, 4, 3, 2, 1

    list.replace(4, 10);

    REQUIRE(list.getIndex(10) == 4);
}

// 15. Testing the addFront() method
TEST_CASE("Test the addFront() method for the dLinkedList", "[dLinkedList]")
{
    dLinkedList<float> list;
    float a[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        list.addFront(a[i]);
    }

    // Note: now, the list contains 5, 4, 3, 2, 1

    for (int i = 5, j = 0; j < 5; i--, j++)
    {
        REQUIRE(list.getItem(j) == a[i - 1]); //checks if the added items are at their respective indices
    }
}

// 16. Testing the addBack() method
TEST_CASE("Test the addBack() method for the dLinkedList", "[dLinkedList]")
{
    dLinkedList<float> list;
    float a[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        list.add(a[i]);
    }

    list.addBack(6);
    REQUIRE(list.getItem(list.getCurrentSize() - 1) == 6); //tests if the last added element was added to the end
    list.addBack(7);
    REQUIRE(list.getItem(list.getCurrentSize() - 1) == 7); //again, tests if the last added element was added to the end

    dLinkedList<float> list2;
    float b[5] = {5, 6, -2, 4.5, 7};

    for (int i = 0; i < 5; i++)
    {
        list2.addBack(a[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        REQUIRE(list2.getItem(i) == a[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        list2.remove(a[i]);
    }

    REQUIRE(list2.isEmpty());
    REQUIRE(list2.getCurrentSize() == 0);
}

// 17. Testing the copy constructor for dLinkedList
TEST_CASE("Test the copy constructor for the dLinkedList", "[dLinkedList]")
{
    dLinkedList<float> list1;
    float a[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        list1.add(a[i]);
    }

    dLinkedList<float> list2(list1); // using the copy constructor to copy all the values over successfully from list 1 to list 2

    for (int i = 0; i < 5; i++) // Checks if all the items have been appropriately copied over
    {
        REQUIRE(list2.getItem(i) == list1.getItem(i));
    }
}

// 18. Debugging and Testing 3 methods - addBack(), remove() and getCurrentSize() to guess and pass the instructor's test 6
// This also tests for getHead() and getTail()
TEST_CASE("Testing and guessing probable errors with passing the instructor's test 6", "[dLinkedList]")
{
    dLinkedList<float> list1;
    float a[5] = {1, 4, 4, 3, 3};

    for (int i = 0; i < 5; i++)
    {
        list1.addBack(a[i]);
    }

    list1.remove(1);
    list1.remove(4);
    REQUIRE(list1.getTail() != nullptr);
    list1.remove(3);
    REQUIRE(list1.getHead() != nullptr);
    list1.remove(3);
    list1.remove(4);
    REQUIRE(list1.getCurrentSize() == 0);
    REQUIRE(list1.getHead() == nullptr);
    REQUIRE(list1.getTail() == nullptr);
}