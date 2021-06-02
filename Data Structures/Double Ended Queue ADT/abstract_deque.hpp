#ifndef ABSTRACT_DEQUE_HPP
#define ABSTRACT_DEQUE_HPP

template <typename T>
class AbstractDeque
{
public:
  /** Returns true if the deque is empty, else false
   */
  virtual bool isEmpty() const noexcept = 0;

  /** Add item to the front of the deque
   * may throw std::bad_alloc
   */
  virtual void pushFront(const T &item) = 0;

  /** Remove the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
  virtual void popFront() = 0;

  /** Returns the item at the front of the deque
   * throws std::runtime_error if the deque is empty
   */
  virtual T front() const = 0;

  /** Add item to the back of the deque
   * may throw std::bad_alloc
   */
  virtual void pushBack(const T &item) = 0;

  /** Remove the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
  virtual void popBack() = 0;

  /** Returns the item at the back of the deque
   * throws std::runtime_error if the deque is empty
   */
  virtual T back() const = 0;
};

#endif
