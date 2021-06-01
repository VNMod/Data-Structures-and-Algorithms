//
//  dNode.hpp
//
//
//  Created by Dr. Tam Chantem on 9/8/20 for VT ECE2574.
//

#ifndef NODE_
#define NODE_

template <class T>

class dNode
{
public:
    /** Default contructor: creates an empty node.
     @return sets data fields appropriately. */
    dNode();

    /** Parameterized contructor: creates a node with anItem as item.
     @param anItem  The object to be put in the "item" field of the node
     @return sets data fields appropriately. */
    dNode(const T &anItem);

    /** Parameterized contructor: creates a node with anItem as item and
     initialized next and prev pointers.
     @param anItem  The object to be put in the "item" field of the node.
     @param nextNodePtr  The pointer to the next node.
     @param prevNodePtr  The pointer to the prev node.
     @return sets data fields appropriately. */
    dNode(const T &anItem, dNode<T> *nextNodePtr, dNode<T> *prevNodePtr);

    /** Sets the item field of the node to anItem.
     @param anItem  The object to be set.
     @return sets the item field appropriately. */
    void setItem(const T &anItem);

    /** Sets the next field of the node to nextNodePtr.
     @param nextNodePtr The pointer to be set.
     @return sets the next field appropriately. */
    void setNext(dNode<T> *nextNodePtr);

    /** Sets the prev field of the node to prevNodePtr.
     @param prevNodePtr The pointer to be set.
     @return sets the prev field appropriately. */
    void setPrev(dNode<T> *prevNodePtr);

    /** Gets the item of the node.
     @return gets the item field of the node. */
    T getItem() const;

    /** Gets the item of the node.
     @return gets the item field of the node. */
    dNode<T> *getNext() const;

    /** Gets the item of the node.
     @return gets the item field of the node. */
    dNode<T> *getPrev() const;

    /** Prints out node information.
     @return displays all the fields of the node. */
    void printNode() const;

private:
    T item;         // A data item
    dNode<T> *next; // Pointer to next node
    dNode<T> *prev; // Pointer to previous node
};

#include "dNode.txx"
#endif