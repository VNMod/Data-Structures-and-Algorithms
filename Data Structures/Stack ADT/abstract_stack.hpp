#ifndef _ABSTRACT_STACK_H_
#define _ABSTRACT_STACK_H_

template <typename T>
class AbstractStack
{
public:

  // push an item of type T into the stack
  virtual bool push(const T& newItem) = 0;

  // pop (remove) the top item from the stack
  virtual bool pop() = 0;

  // return item at the top of the stack
  virtual const T& peek() const = 0;

  // returns true if the stack is empty
  virtual bool isEmpty() const = 0;
};


#endif // _ABSTRACT_STACK_H_
