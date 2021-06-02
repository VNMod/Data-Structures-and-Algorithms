
/** ADT Stack implementation.
    @file Stack.hpp  */
#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>

#include "abstract_stack.hpp"

template <typename T>
class Stack : public AbstractStack<T>
{
public:
    /** Stack constructor 
   * Creates a stack that will hold 100 items
   */
    Stack();

    /** Stack destructor. Must delete any allocated memory. */
    virtual ~Stack();

    /** Copy Constructor */
    Stack(const Stack &rhs);

    /** Returns the number of items on the stack.
      @return The integer number of items on the stack. */
    size_t size() const;

    /** Determines whether this stack is empty.
      @return True if the stack has no items, or false if not. */
    bool isEmpty() const;

    /** Pushes a new entry onto the top of the stack.  Grows the stack array, if necessary.
      @post  If successful, newItem is on the top of the stack.
      @param newItem  The item (of datatype T) to be pushed on top of the stack.
      @return  True if insert was successful, or false if not. */
    bool push(const T &newItem);

    /** Pops the top item off of the stack. The stack size is decreased by 1.
      @return  True if successful, or false otherwise. */
    bool pop();

    /** Returns the top item off of the stack without removing it. The stack size
      stays the same.
      @return  Item of T that was on the top of the stack. 
      Throws an exception of type range_error if the stack is empty. */
    const T &peek() const throw(std::range_error);

    /** Deletes all entries on the stack.
      @post  Stack contains no items, and the size of the stack is 0. */
    void clear();

private:
    /** Index for the top of the stack
   */
    size_t top;

    /** Number of items the stack can hold
   */
    size_t capacity;

    /** Stack entries
   */
    T *items;
}; // end Stack

#include "Stack.txx"
#endif
