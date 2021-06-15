// Edited by Varun Nimish Modak for Project 1.1,
// Data Structures and Algorithms, Virginia Tech

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include "ListInterface.hpp"
#include "dNode.hpp"

template <class T>

class dLinkedList : public ListInterface<T>
{
public:
    /** Default contructor: creates a list with zero items
     @return sets data fields appropriately */
    dLinkedList();

    /** Copy constructor: performs a deep copy of alist. If alist is empty, then
     the new list is also empty.
     @return sets data fields appropriately. */
    dLinkedList(const dLinkedList<T> &alist);

    /** Destructor: deallocates memory and sets all pointers to nullptr. */
    virtual ~dLinkedList();

    /** --------------------------------------------------------------------
            Methods that are specified in listInterface.hpp.
        -------------------------------------------------------------------- */

    /** Gets the current number of entries in this list.
     @return The integer number of entries currently in the list. */
    int getCurrentSize() const;

    /** Sees whether this list is empty.
     @return True if the list is empty, or false if not. */
    bool isEmpty() const;

    /** Adds a new entry to the list.
     @post  If successful, newEntry is stored in the list and
     the count of items in the list has increased by 1.
     @param newEntry  The object to be added as a new entry.
     @return  True if addition was successful, or false if not. */
    bool add(const T &newEntry);

    /** Removes one occurrence of a given entry from this list,
     if possible.
     @post  If successful, anEntry has been removed from the list
     and the count of items in the list has decreased by 1.
     @param anEntry  The entry to be removed.
     @return  True if removal was successful, or false if not. */
    bool remove(const T &anEntry);

    /** Removes all entries from this list.
     @post  list contains no items, and the count of items is 0. */
    void clear();

    /** Counts the number of times a given entry appears in list.
     @param anEntry  The entry to be counted.
     @return  The number of times anEntry appears in the list. */
    int getFrequencyOf(const T &anEntry) const;

    /** Tests whether this list contains a given entry.
     @param anEntry  The entry to locate.
     @return  True if list contains anEntry, or false otherwise. */
    bool contains(const T &anEntry) const;

    /** Inserts a new entry at the position specified by index, where index = 0 refers to
     the first entry in the list. If index + 1 > itemCount, then the new entry is added to
     the back of the list.
     @post  If successful, newEntry is stored as the specified position of the list (or at the
     back of the list) and the count of items in the list has increased by 1.
     @param newEntry  The object to be added as a new entry.
     @param index   The index of the list to insert the item at.
     @return  True if addition was successful, or false if not. */
    bool insertAt(const T &newEntry, const int index);

    /** Removes the entry at the position specified by index, where index = 0 refers to
     the first entry in the list. If index + 1 > itemCount, then this method does nothing.
     @post  If successful, the item at the specified position is removed, unless the
     specified index does not exist in the list.
     @param index   The index of the list to remove the item at.
     @return  True if removal was successful, or false if not. */
    bool removeAt(const int index);

    /** Replaces the entry at the specified index with newEntry. Does nothing if
     the specified index does not exists, where index starts at 0.
     @param index   The index of the list at which to replace the item.
     @param newEntry  The object to replace at the specified index.
     @return True if replacement was successful, or false if not. */
    bool replace(const int index, const T &newEntry);

    /** Returns the index of the first occurance of anEntry.
     @param anEntry  The object to find.
     @return A valid index if the object is found, and -1 if it is not. */
    int getIndex(const T &anEntry) const;

    /** Returns the item at the position specified by index where index starts at 0.
     @pre index must be between 0 and itemCount - 1.
     @param index   The index of the item to be returned.
     @return A valid item if the index is between 0 and itemCount - 1. If somehow
     index < 1 or index > itemCount, print out the following error message to standard out (stdout): "Invalid index to getItem()" and return a blank default object.*/
    T getItem(const int index) const;

    /** Prints the content of the list to the screen. */
    void printList() const;

    /** Prints the content of the list in reverse order to the screen. */
    void printReverseList() const;

    /** --------------------------------------------------------------------
     Methods that are specific to dLinkedList
     -------------------------------------------------------------------- */

    /** Adds a new entry to the "front" of the list (as the first entry).
     @post  If successful, newEntry is stored as the first item of the list and
     the count of items in the list has increased by 1.
     @param newEntry  The object to be added as a new entry.
     @return  True if addition was successful, or false if not. */
    bool addFront(const T &newEntry);

    /** Adds a new entry to the "back" of the list (as the last entry).
     @post  If successful, newEntry is stored as the last item of the list and
     the count of items in the list has increased by 1.
     @param newEntry  The object to be added as a new entry.
     @return  True if addition was successful, or false if not. */
    bool addBack(const T &newEntry);

    /** Gets the head pointer of the linked list list.
     @return The head pointer of the list */
    dNode<T> *getHead() const;

    /** Gets the tail pointer of the linked list list.
     @return The tail pointer of the list */
    dNode<T> *getTail() const;

private:
    dNode<T> *headPtr; // Head pointer of the linked list list
    dNode<T> *tailPtr; // Tail pointer of the linked list list
    int itemCount;     // Current count of list items

    dNode<T> *getPointerTo(const T &target) const;
};

#include "dLinkedList.txx"
#endif
