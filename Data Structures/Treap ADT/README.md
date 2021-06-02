# Deque ADT

This repository contains:

- a Deque class that derives from a virtual class called AbstractDeque.

## OVERVIEW:

- The ADT implementation for the Deque class can be found in Stack.txx.

### Key Concepts Covered:

- Deque (Double Ended Queue that allows both enqueuing and dequeueing from back and front) ADT

### Deque:

The Deque class supports:

- a default constructor that creates a deque capable of storing 64 items
- a (deep) copy constructor
- a copy-assignment operator
- a destructor
- a method to push items to the front of the deque
- a method to pop items from the front of the deque
- a method to push items to the back of the deque
- a method to pop items from the back of the deque
- a method to peek/view the back most item of the deque without removal
- a method to peek/view the front most item of the deque without removal.

### Note: if the limit of the Deque is reached, then a growing strategy has been employed where the limit size doubles so that more items can be enqueued onto the Queue.

Also note:

Back of the Deque ---------> Front of the Deque
