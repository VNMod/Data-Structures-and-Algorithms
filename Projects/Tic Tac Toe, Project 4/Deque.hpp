#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"

template <typename T>
class Deque : public AbstractDeque<T>
{

  // TODO:
public:
  //Default Constructor
  Deque();

  //Destructor
  virtual ~Deque();

  //Copy Constructor
  Deque(const Deque &rhs);

  //Copy-Assignment Operator
  Deque<T> &operator=(Deque<T> deq);

  //Returns true if the deque is empty, else false
  bool isEmpty() const noexcept;

  /** Add item to the front of the deque
   * may throw std::bad_alloc
   */
  void pushFront(const T &item);

  /** Remove the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
  void popFront();

  /** Returns the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
  T front() const;

  /** Add item to the back of the deque
   * may throw std::bad_alloc
   */
  void pushBack(const T &item);

  /** Remove the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
  void popBack();

  /** Returns the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
  T back() const;

  // // Deletes all entries in the double ended queue.
  // void clear();

  // // Returns the number of items in the deque
  // size_t size() const;

private:
  //Number of items the queue can hold
  size_t capacity;

  //Index for the back of the queue
  int backi;

  //Index for the front of the queue
  int fronti;

  // Deque entries
  T *items;

  // Number of items currently in the queue
  size_t count;

  // Returns the index of the back element
  int return_back_index() const;

  // Returns the index of the front element
  int return_front_index() const;

}; //end Deque

#include "Deque.txx"
#endif
