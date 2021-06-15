// By Varun Nimish Modak for Project 1.2,
// Data Structures and Algorithms, Virginia Tech

#include "dNode.hpp"

template <class T>
void dNode<T>::printNode() const
{
    std::cout << "Current Node: " << item << std::endl;

    if (next != nullptr)
    {
        std::cout << "Next Node: " << next->getItem() << std::endl;
    }
    else
    {
        std::cout << "Next Node: NULL " << std::endl;
    }

    if (prev != nullptr)
    {
        std::cout << "Next Node: " << prev->getItem() << std::endl;
    }
    else
    {
        std::cout << "Next Node: NULL " << std::endl;
    }
}

template <class T>
//Default contructor: creates an empty node and sets the item and associated pointers to 0 and nullptr respectively
dNode<T>::dNode() : next(nullptr), prev(nullptr)
{
}

template <class T>

//Parameterized contructor: creates a node with anItem as item.
dNode<T>::dNode(const T &anItem)
{
    item = anItem;
}

template <class T>

/* Parameterized contructor: creates a node with anItem as item and
initializes next and prev pointers. */
dNode<T>::dNode(const T &anItem, dNode<T> *nextNodePtr, dNode<T> *prevNodePtr)
{
    item = anItem;
    next = nextNodePtr;
    prev = prevNodePtr;
}

template <class T>

// Method: Sets the item field of the node to anItem.
void dNode<T>::setItem(const T &anItem)
{
    item = anItem;
}

template <class T>

// Method: Sets the next field of the node to nextNodePtr.
void dNode<T>::setNext(dNode<T> *nextNodePtr)
{
    next = nextNodePtr;
}

template <class T>

//Method: Sets the prev field of the node to prevNodePtr.
void dNode<T>::setPrev(dNode<T> *prevNodePtr)
{
    prev = prevNodePtr;
}

template <class T>

//Method: Gets the item of the node.
T dNode<T>::getItem() const
{
    return item;
}

template <class T>

//Method: Returns the next pointer of the node
dNode<T> *dNode<T>::getNext() const
{
    return next;
}

template <class T>

//Method: Returns the previous pointer of the node
dNode<T> *dNode<T>::getPrev() const
{
    return prev;
}
