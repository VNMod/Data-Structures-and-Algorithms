//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

//  Modified by Tam Chantem on 09/09/20.

#ifndef LIST_INTERFACE_
#define LIST_INTERFACE_

#include <vector>

template<class T>
class ListInterface
{
public:
    /** Gets the current number of entries in this list.
     @return The integer number of entries currently in the list. */
    virtual int getCurrentSize() const = 0;
    
    /** Sees whether this list is empty.
     @return True if the list is empty, or false if not. */
    virtual bool isEmpty() const = 0;
   
    /** Adds a new entry to the list.
     @post  If successful, newEntry is stored in the list and
       the count of items in the list has increased by 1.
     @param newEntry  The object to be added as a new entry.
     @return  True if addition was successful, or false if not. */
    virtual bool add(const T& newEntry) = 0;
    
    /** Removes one occurrence of a given entry from this list,
        if possible.
     @post  If successful, anEntry has been removed from the list
        and the count of items in the list has decreased by 1.
     @param anEntry  The entry to be removed.
     @return  True if removal was successful, or false if not. */
    virtual bool remove(const T& anEntry) = 0;
   
    /** Removes all entries from this list.
    @post  List contains no items, and the count of items is 0. */
    virtual void clear() = 0;
   
    /** Counts the number of times a given entry appears in list.
     @param anEntry  The entry to be counted.
     @return  The number of times anEntry appears in the list. */
    virtual int getFrequencyOf(const T& anEntry) const = 0;
   
    /** Tests whether this list contains a given entry.
     @param anEntry  The entry to locate.
     @return  True if list contains anEntry, or false otherwise. */
    virtual bool contains(const T& anEntry) const = 0;
    
    /** Inserts a new entry at the position specified by index, where index = 0 refers to
     the first entry in the list. If index + 1 > itemCount, then the new entry is added to
     the back of the list.
     @post  If successful, newEntry is stored as the specified position of the list (or at the
     back of the list) and the count of items in the list has increased by 1.
     @param newEntry  The object to be added as a new entry.
     @param index   The index of the list to insert the item at.
     @return  True if addition was successful, or false if not. */
    virtual bool insertAt(const T& newEntry, const int index) = 0;
    
    /** Removes the entry at the position specified by index, where index = 0 refers to
     the first entry in the list. If index + 1 > itemCount, then this method does nothing.
     @post  If successful, the item at the specified position is removed, unless the
     specified index does not exist in the list.
     @param index   The index of the list to remove the item at.
     @return  True if removal was successful, or false if not. */
    virtual bool removeAt(const int index) = 0;
    
    /** Replaces the entry at the specified index with newEntry. Does nothing if
     the specified index does not exists, where index starts at 0.
     @param index   The index of the list at which to replace the item.
     @param newEntry  The object to replace at the specified index.
     @return True if replacement was successful, or false if not. */
    virtual bool replace(const int index, const T& newEntry) = 0;
    
    /** Returns the index of the first occurance of anEntry.
     @param anEntry  The object to find.
     @return A valid index if the object is found, and -1 if it is not. */
    virtual int getIndex(const T& anEntry) const = 0;
    
    /** Returns the item at the position specified by index where index starts at 0.
     @pre index must be between 0 and itemCount - 1.
     @param index   The index of the item to be returned.
     @return A valid item if the index is between 0 and itemCount - 1. If somehow
     index < 1 or index > itemCount, print out the following error message to standard out (stdout): "Invalid index to getItem()" and return a blank default object.*/
    virtual T getItem(const int index) const = 0;
    
    /** Prints the content of the list to the screen. */
    virtual void printList() const = 0;
    
    /** Prints the content of the list in reverse order to the screen. */
    virtual void printReverseList() const = 0;
}; 
#endif
