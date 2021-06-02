# Stack ADT

This repository contains:

- a Stack class that derives from a virtual class called AbstractStack.

## OVERVIEW:

- The ADT implementation for the Stack class can be found in Stack.txx.

### Key Concepts Covered:

- Stack (Array Implementation using dynamic memory)

### Stack:

The Stack class supports:

- a default constructor that creates a stack capable of storing 100 items
- a (deep) copy constructor
- a destructor
- a method to get the stack size (i.e. the number of items on the stack)
- a method to determine if the stack is empty
- a method to push an item onto the stack
- a method to pop/remove an item off the stack
- a method to peek/view the topmost item of the stack without removal
- a method to clear (empty) the stack.

*Note: if the limit of the Stack is reached, then a growing strategy has been employed where the limit size doubles so that more items can be pushed on to the stack.*
