# Double Linked List ADT

This repository contains:

- a dNode class for each of a double linked list, i.e. it contains a pointer to the next and previous node.
- a dLinkedList class that implements the double (doubly) linked list that derives from a virtual class called ListInterface.

## OVERVIEW:

- The ADT implementations for both the dNode and dLinkedList can be found in dNode.txx and dLinkedList.txx.

### Key Concepts Covered:

- Double Linked Lists
- Dynamic Memory Allocation and Pointers

### dNode:

The dNode class supports:

- a default constructor that creates an empty node and null pointers
- construction of a node initialized with an item as its data field
- construction of a node initialized with an item as its data field, as well as next and previous pointers • method to set the item field of a node
- method to set the next pointer of a node
- method to set the previous pointer of a node
- method to get the item field of a node
- method to get the next pointer of a node
- method to get the previous pointer of a node

### dLinkedList:

The dLinkedList class supports:

- a default constructor that creates an empty list
- a (deep) copy constructor
- a destructor
- method to get the current list size
- method to get the head pointer
- method to get the tail pointer
- method to get the index of an entry
- method to get the item given an index
- method to determine if the list is empty
- methods to add a new entry to the list
- methods to remove an entry from the list
- method to clear (empty) the list
- method to determine the number of times an entry appears in the list • method to determine whether the list contains a given entry
- method to replace an entry


