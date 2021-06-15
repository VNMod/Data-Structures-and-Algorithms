//Edited by Varun Nimish Modak for Project 1.1

#include "dLinkedList.hpp"
#include "dNode.hpp"
#include <iostream>

template <class T>
void dLinkedList<T>::printList() const
{
    std::cout << "Printing out content of list of size: " << itemCount << std::endl;
    std::cout << "The items are: "
              << "\t";

    dNode<T> *curPtr = headPtr;
    int counter = 0;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        std::cout << curPtr->getItem() << "\t";
        curPtr = curPtr->getNext();
        counter++;
    }
    std::cout << std::endl;
}

template <class T>
void dLinkedList<T>::printReverseList() const
{
    std::cout << "Printing out (in reverse) content of list with size: " << itemCount << std::endl;
    std::cout << "The items are: "
              << "\t";

    dNode<T> *curPtr = tailPtr;
    int counter = 0;
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        std::cout << curPtr->getItem() << "\t";
        curPtr = curPtr->getPrev();
        counter++;
    }
    std::cout << std::endl;
}

// the new Function Definitions:

template <class T>
// Default contructor: creates a list with zero items
dLinkedList<T>::dLinkedList() : itemCount(0), headPtr(nullptr), tailPtr(nullptr)
{
}

template <class T>
// Copy constructor: performs a deep copy of a list. If a list is empty, then the new list is also empty.
dLinkedList<T>::dLinkedList(const dLinkedList<T> &alist)
{
    itemCount = alist.itemCount;

    // a new pointer called origPtr_head that tracks which Node we're copying from the ORIGINAL CHAIN
    dNode<T> *origPtr_head = alist.getHead();

    dNode<T> *origPtr_tail = alist.getTail();

    if (origPtr_head == nullptr) // if the list is empty
    {
        headPtr = nullptr; // thus, even the copy is empty
        tailPtr = nullptr;
    }
    else
    {
        //Copying the first node:
        dNode<T> *firstNodePtr = new dNode<T>();
        headPtr = firstNodePtr;
        headPtr->setItem(origPtr_head->getItem()); //returns the item of the first Node

        origPtr_head = origPtr_head->getNext(); //Advance the ORIGINAL CHAIN's pointer to copy the next item/Node
        //Copying the remaining nodes:

        //This newChainPtr allows us to traverse along the list as we keep track of which Node we're at and copy
        dNode<T> *newChainPtr = headPtr;

        while (origPtr_head != nullptr) //until the end of the list hasn't been reached
        {
            T next_item = origPtr_head->getItem(); //Get next item from the ORIGINAL CHAIN

            dNode<T> *newNodePtr = new dNode<T>(next_item); //Create a new node containing this next item

            newChainPtr->setNext(newNodePtr); //Link this new node to the end of the new chain

            newNodePtr->setPrev(newChainPtr); //The prev of the new Node points to the previous Node.

            newChainPtr = newNodePtr; //Advance the new chain's pointer to point to the new last node

            origPtr_head = origPtr_head->getNext(); //Advance the ORIGINAL CHAIN's pointer

            newNodePtr = nullptr;
            delete newNodePtr;
            newNodePtr = nullptr;
        }

        tailPtr = newChainPtr; //Advance the tailptr to point to the new last node

        newChainPtr->setNext(nullptr); //As the next of the last Node must be a nullptr

        newChainPtr = nullptr;

        firstNodePtr = nullptr;
        delete firstNodePtr;
        firstNodePtr = nullptr;
    }

    origPtr_head = nullptr;
    origPtr_tail = nullptr;
}

template <class T>
// Destructor: deallocates memory and sets all pointers to nullptr
dLinkedList<T>::~dLinkedList()
{
    clear();
}

template <class T>
// Method: gets the current number of entries in this list
int dLinkedList<T>::getCurrentSize() const
{
    return itemCount;
}

template <class T>
// Method: sees whether this list is empty.
bool dLinkedList<T>::isEmpty() const
{
    return (itemCount == 0);
}

// Method: adds a new entry to the list.
template <class T>
bool dLinkedList<T>::add(const T &newEntry)
{
    dNode<T> *newNodePtr = new dNode<T>(); //new node/item to be added to the list
    newNodePtr->setItem(newEntry);
    if (headPtr != nullptr) //if list is already not empty
    {
        newNodePtr->setNext(headPtr); //Connects the new item to the list
        headPtr->setPrev(newNodePtr); //further, establishes the link by setting the Prev of the newly second node to point to the new first node
        newNodePtr->setPrev(nullptr); //Prev of the first node must be nullptr
    }
    else //if the list is empty, and we're attempting to add a node
    {
        newNodePtr->setNext(nullptr);
        newNodePtr->setPrev(nullptr);
    }

    headPtr = newNodePtr; //headPtr points to the new Node added at the beginning of the list

    itemCount++;

    if (itemCount == 1) //if the list was previously empty but now with one item, the tailPtr is set to point to the first Node
        tailPtr = headPtr;

    newNodePtr = nullptr;
    delete newNodePtr; //deletes the pointer
    newNodePtr = nullptr;

    return true;
}

// Method: Removes one occurrence of a given entry from this list, if possible.
template <class T>
bool dLinkedList<T>::remove(const T &anEntry)
{
    bool success = false;

    if (!isEmpty() && getFrequencyOf(anEntry) >= 1 && getPointerTo(anEntry) != nullptr) //if item exists and the list isn't empty
    {
        success = true;

        dNode<T> *entryNodePtr = getPointerTo(anEntry); // finds pointer to that Node; essentially the Node's location

        // Copy data from the first Node to this located Node
        entryNodePtr->setItem(headPtr->getItem());

        if (headPtr != tailPtr) //if first Node is not the only item of the list
        {
            dNode<T> *nodeToDelete = headPtr;
            //advance the head pointer to the new first node as first node has been deleted
            headPtr = headPtr->getNext();
            headPtr->setPrev(nullptr);
            //setting the pointers of the old first node, to be deleted, to nullptr
            delete nodeToDelete; //removing the item
            nodeToDelete = nullptr;
            itemCount--; //updating list's item count
        }
        else // If there's only one node left to remove
        {
            dNode<T> *nodeToDelete = headPtr;
            headPtr->setNext(nullptr);
            headPtr = nullptr;
            tailPtr = nullptr;
            delete nodeToDelete; //removing the item
            nodeToDelete = nullptr;
            itemCount--; //updating list's item count
        }

        entryNodePtr = nullptr;
    }

    return success;
}

// Method: Removes all entries from this list.
template <class T>
void dLinkedList<T>::clear()
{

    while (headPtr != nullptr) //while the list is not already empty
    {
        if (headPtr != tailPtr) //if the first Node is not the only item of the list
        {
            dNode<T> *nodeToDelete = headPtr;
            headPtr = headPtr->getNext();
            headPtr->setPrev(nullptr);
            delete nodeToDelete;
            nodeToDelete = nullptr;
            itemCount--;
        }
        else //if there's only one item left to remove
        {
            dNode<T> *nodeToDelete = headPtr;
            headPtr = nullptr;
            tailPtr = nullptr;
            delete nodeToDelete;
            nodeToDelete = nullptr;
            itemCount--;
        }
    }
}

// Method: Counts the number of times a given entry appears in list.
template <class T>
int dLinkedList<T>::getFrequencyOf(const T &anEntry) const
{
    int frequency = 0;
    int counter = 0;
    dNode<T> *curPtr = headPtr;

    //Condition: to search the list if it is not empty & the index doesn't exceed the size of the list
    while ((curPtr != nullptr) && (counter < itemCount))
    {
        if (anEntry == curPtr->getItem())
        {
            frequency++;
        }
        counter++;
        curPtr = curPtr->getNext();
    }

    curPtr = nullptr;
    return frequency;
}

// Method: Tests whether this list contains a given entry.
template <class T>
bool dLinkedList<T>::contains(const T &anEntry) const
{
    return (getPointerTo(anEntry) != nullptr);
}

// Method: Returns either a pointer to the specified node containing a given entry or nullptr if entry doesn't exist
template <class T>
dNode<T> *dLinkedList<T>::getPointerTo(const T &target) const
{
    bool Nodefound = false;

    dNode<T> *curPtr = headPtr;

    //Condition: to search the list as long as the item has not been found and the list is not empty
    while (!Nodefound && (curPtr != nullptr))
    {
        if (target == curPtr->getItem())
            Nodefound = true;
        else
            curPtr = curPtr->getNext();
    }
    if (!Nodefound) //if the item doesn't exist in the list, nullptr is returned
    {
        curPtr = nullptr;
        delete curPtr;
        curPtr = nullptr;
        return nullptr;
    }
    else
        return curPtr;
}

/* Method: inserts a new entry at the position specified by index, where index = 0 refers to
the first entry in the list. If index + 1 > itemCount, then the new entry is added to
the back of the list.*/
template <class T>
bool dLinkedList<T>::insertAt(const T &newEntry, const int index)
{
    bool success = false;

    dNode<T> *curNodePtr = headPtr;
    dNode<T> *previousNodePtr = nullptr;

    int counter = 0;
    // if the item index doesn't exceed the (size-1) and it is not negative
    if (index + 1 <= itemCount && index > 0)
    {
        //Condition: to find the pointer to the Node at a certain index, provided the list is not empty
        while (counter < index && headPtr != nullptr)
        {
            previousNodePtr = curNodePtr;
            curNodePtr = curNodePtr->getNext();
            counter++;
        }

        dNode<T> *newNodePtr = new dNode<T>(); // Creates the new node to be inserted

        newNodePtr->setItem(newEntry); // Data is assigned to the Node as per the NewEntry of T type passed by reference

        newNodePtr->setPrev(previousNodePtr); // New Node's prev should point to the previous Node

        if (itemCount != 0) //if the list wasn't previously empty
        {
            previousNodePtr->setNext(newNodePtr); // Previous Node's next should point to the new Node at the given index
            newNodePtr->setNext(curNodePtr);      // New Node's next should point to the Node that was previously at the same index
            curNodePtr->setPrev(newNodePtr);      // the Node that was previously at the same index should have its prev point to the new Node
        }
        else //if the list was empty, and you're adding a new item
        {
            tailPtr = newNodePtr; // both tailPtr and headPtr must point to the new Node
            headPtr = newNodePtr;
        }

        itemCount++;

        newNodePtr = nullptr;
        delete newNodePtr;

        success = true;
    }
    else if (index + 1 > itemCount) //if the index exceeds the itemCount, the item is added at the back by default
    {
        addBack(newEntry);
        success = true;
    }
    else if (index == 0) //if the index is 0, then we must add at the front of the list
    {
        addFront(newEntry);
        success = true;
    }

    curNodePtr = nullptr;

    previousNodePtr = nullptr;

    return success;
}

/* Method: Removes the entry at the position specified by index, where index = 0 refers to
the first entry in the list. If index + 1 > itemCount, then this method does nothing.*/
template <class T>
bool dLinkedList<T>::removeAt(const int index)
{
    bool success = false;

    dNode<T> *findNodeTBD = headPtr; //findNodeTBD stands for: find the node to be deleted (via index)
    dNode<T> *previousNodePtr = nullptr;

    int counter = 0;

    //find the node to be deleted while list isn't empty, the item exists and there's more than one item in the list
    while (counter < index && headPtr != nullptr && itemCount > 1)
    {
        previousNodePtr = findNodeTBD;
        findNodeTBD = findNodeTBD->getNext();
        counter++;
    }

    if (index + 1 <= itemCount) //if the index exists within the itemCount
    {
        if (findNodeTBD->getNext() != nullptr && findNodeTBD->getPrev() != nullptr) //if in between the list
        {
            dNode<T> *nextNodePtr;
            nextNodePtr = findNodeTBD->getNext();  //nextNodePtr points to the next node
            nextNodePtr->setPrev(previousNodePtr); //de-linking the current Node, to be deleted, from the list
            previousNodePtr->setNext(nextNodePtr); //also de-linking, but maintaining the list chain
            delete findNodeTBD;
            nextNodePtr = nullptr;
        }
        else if (headPtr == tailPtr) //removing the final item of the list, if only one item is left
        {
            dNode<T> *nodeToDelete = headPtr;
            headPtr->setNext(nullptr);
            headPtr = nullptr;
            tailPtr = nullptr;
            delete nodeToDelete; //removing the item
            nodeToDelete = nullptr;
        }
        else if (findNodeTBD->getNext() == nullptr) //removing the last Node
        {
            dNode<T> *nextNodePtr;
            previousNodePtr->setNext(nullptr);
            tailPtr = previousNodePtr;
            delete findNodeTBD;
            nextNodePtr = nullptr;
        }
        else if (findNodeTBD->getPrev() == nullptr) //removing the first Node
        {
            dNode<T> *nextNodePtr;
            headPtr = findNodeTBD->getNext();
            delete findNodeTBD;
            nextNodePtr = nullptr;
        }

        itemCount--; //updating list's item count
        success = true;
    }

    findNodeTBD = nullptr;
    previousNodePtr = nullptr;
    return success;
}

/* Method: Replaces the entry at the specified index with newEntry. Does nothing if
the specified index does not exists, where index starts at 0. */
template <class T>
bool dLinkedList<T>::replace(const int index, const T &newEntry)
{
    bool success = false;
    int counter = 0;
    dNode<T> *findNodePtr = headPtr;
    if (index + 1 <= itemCount && headPtr != nullptr) // if the specified index does exist
    {
        while (counter < index) //finding the pointer to the Node via the specified index
        {
            if (tailPtr != nullptr)
            {
                findNodePtr = findNodePtr->getNext(); //advancing the pointer to the next Node
                counter++;
            }
        }
        findNodePtr->setItem(newEntry);
        success = true;
    }

    findNodePtr = nullptr;

    return success;
}

// Method: Returns the index of the first occurance of anEntry.
template <class T>
int dLinkedList<T>::getIndex(const T &anEntry) const
{
    int index = 0;
    dNode<T> *findNodePtr = headPtr;
    bool foundIndex = false;

    //Condition: to find the index of the node while the list isn't empty and the item exists
    while (index < itemCount && headPtr != nullptr)
    {
        if (findNodePtr->getItem() == anEntry) //if the item of the Node matches the entry, break the loop
        {
            foundIndex = true;
            break;
        }
        else
        {
            findNodePtr = findNodePtr->getNext(); //advancing the pointer to the next Node
            index++;                              //else increment the index
        }
    }

    //if the the item doesn't exist in the list or the index hasn't been found, return -1
    if (foundIndex == false)
        index = -1;

    findNodePtr = nullptr;

    return index;
}

// Method: Returns the item at the position specified by index, given index starts at 0.
template <class T>
T dLinkedList<T>::getItem(const int index) const
{
    int counter = 0;

    dNode<T> *findNodePtr = headPtr;

    while (counter < index && headPtr != nullptr && index > 0) //finding the pointer to the Node at a certain index
    {
        findNodePtr = findNodePtr->getNext(); //advancing the pointer to point to the next Node
        counter++;
    }

    T item = findNodePtr->getItem(); //finding the item at the given index

    if (index < 0 || index > itemCount) //if the index doesn't exist or it exceeds the allowed value of (size - 1)
    {
        std::cout << std::endl;
        std::cout << "Error, invalid index to getItem()";
    }

    findNodePtr = nullptr;

    return item;
}

// Method: Adds a new entry to the "front" of the list (as the first entry).
template <class T>
bool dLinkedList<T>::addFront(const T &newEntry)
{
    dNode<T> *newNodePtr = new dNode<T>();
    newNodePtr->setItem(newEntry);
    if (headPtr != nullptr) //if list is not empty already
    {
        newNodePtr->setNext(headPtr); //New node points to the chain
        headPtr->setPrev(newNodePtr);
        newNodePtr->setPrev(nullptr);
    }
    else // if it is empty, and we're adding a node
    {
        newNodePtr->setNext(nullptr);
        newNodePtr->setPrev(nullptr);
    }

    headPtr = newNodePtr; //headPtr points to the new Node added at the beginning of the list

    itemCount++;

    if (itemCount == 1) //if the list was previously empty but now has one item, the tailPtr is set to point to the first Node
        tailPtr = headPtr;

    newNodePtr = nullptr;
    delete newNodePtr;
    newNodePtr = nullptr;

    return true;
}

// Method: Adds a new entry to the "back" of the list (as the last entry).
template <class T>
bool dLinkedList<T>::addBack(const T &newEntry)
{
    dNode<T> *newNodePtr = new dNode<T>();        //new Node to be added
    newNodePtr->setItem(newEntry);                //adding the entry to the added Node
    if (headPtr != nullptr && tailPtr != nullptr) //if more than one items in the list
    {
        newNodePtr->setPrev(tailPtr); //connecting the Node to the list
        tailPtr->setNext(newNodePtr); //connecting the Node to the list
        tailPtr = newNodePtr;         //setting the tail pointer to the new Node as it's now the last entry
    }
    else if (tailPtr == nullptr) //if the list was previously empty
    {
        tailPtr = newNodePtr;
        headPtr = newNodePtr;
    }

    newNodePtr = nullptr;
    delete newNodePtr;
    newNodePtr = nullptr;

    itemCount++;

    return true;
}

// Method: Gets the head pointer of the linked list list.
template <class T>
dNode<T> *dLinkedList<T>::getHead() const
{
    return headPtr;
}

// Method: Gets the tail pointer of the linked list list.
template <class T>
dNode<T> *dLinkedList<T>::getTail() const
{
    return tailPtr;
}
