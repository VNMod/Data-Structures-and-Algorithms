// By Varun Nimish Modak for Project 2.1,
// Data Structures and Algorithms, Virginia Tech

#include "Stack.hpp"
#include <iostream>

#define SIZE 2

// Default Stack Constructor: Creates a stack that will hold 100 items
template <typename T>
Stack<T>::Stack() : top(0)
{
    capacity = 100;

    //items points to the newly created array-based stack
    items = new T[capacity]; //stack is of size 100
}

// Stack destructor: Must delete any allocated memory
template <typename T>
Stack<T>::~Stack()
{
    clear();
}

// Copy Constructor: Performs a deep copy of another Stack object
template <typename T>
Stack<T>::Stack(const Stack &rhs)
{
    capacity = rhs.capacity; //copying the capacity of the rhs Stack

    //items points to the newly created array-based stack
    items = new T[capacity]; //stack is of size 100

    if (rhs.size() != 0)
    {
        int i = 0;
        while (i < rhs.size())
        {
            items[i] = rhs.items[i];
            i++;
        }

        top = rhs.top;
    }
}

// Method: Returns the number of items on the stack
template <typename T>
size_t Stack<T>::size() const
{
    return top;
}

// Method: Determines whether this stack is empty
template <typename T>
bool Stack<T>::isEmpty() const
{
    if (size() == 0)
        return true;
    else
        return false;
}

// Method: Pushes a new entry onto the top of the stack.  Grows the stack array, if necessary
template <typename T>
bool Stack<T>::push(const T &newItem)
{
    if (size() < capacity)
    {
        items[top] = newItem; //pushing the new item
        top++;                //indicates the increase in size and latest item index
        return true;
    }
    else //grow the stack using a special push operation, i.e. N = N * SIZE (here, growing SIZE is 2x)
    {
        capacity = capacity * SIZE;
        T *itemp;
        itemp = new T[capacity]; //newly dynamically allocated array

        int i = 0;
        while (i < size())
        {
            itemp[i] = items[i];
            i++;
        }

        delete[] items; //deleting the previous array

        items = itemp; //now the items pointer points to the newly created array of items

        itemp = nullptr;
        delete itemp;

        //NOW, PUSHING THE ITEM
        items[top] = newItem;
        top++; //indicates the increase in size and latest item index
        return true;
    }
}

// Method: Pops the top item off of the stack. The stack size is decreased by 1
template <typename T>
bool Stack<T>::pop()
{
    if (size() > 0)
    {
        T *itemp;
        itemp = new T[capacity]; //newly dynamically allocated array

        int i = 0;
        while (i < (size() - 1)) //popping the top item of the stack
        {
            itemp[i] = items[i];
            i++;
        }

        delete[] items;

        items = itemp; //now the items pointer points to the newly created array of items

        itemp = nullptr;

        delete itemp; //deleting the newly created and allocated array

        top--;
        return true;
    }
    else
        return false;
}

// Method: Returns the top item off of the stack without removing it. The stack size stays the same.
template <typename T>
const T &Stack<T>::peek() const throw(std::range_error)
{
    try
    {
        if (size() == 0)
            throw std::range_error("The stack is empty!");
    }
    catch (std::logic_error &ex)
    {
        std::cout << "I catch logical errors" << ex.what() << std::endl;
    }
    return items[top - 1]; //returning the last item of the stack
}

// Method: Deletes all entries on the stack
template <typename T>
void Stack<T>::clear()
{
    delete[] items; //deleting the stack altogether
    items = nullptr;
    top = 0;
}
