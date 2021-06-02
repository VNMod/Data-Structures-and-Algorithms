// By Varun Nimish Modak for Project 3.1,
// Data Structures and Algorithms, Virginia Tech

#include "Deque.hpp"
#include <iostream>

// GROWTH FACTOR for growing strategy
#define GROWTH 2

template <typename T>
//Default Constructor that creates a deque capable of storing 64 items
Deque<T>::Deque()
{
    capacity = 64; //initial capacity of the dequeue

    count = 0; //initial size of the dequeue

    backi = -1;

    fronti = -1;

    items = new T[capacity]; //dequeue is of size 64
}

//Destructor
template <typename T>
Deque<T>::~Deque()
{
    delete[] items; //deleting the deque
    items = nullptr;
}

//Copy Constructor:
template <typename T>
Deque<T>::Deque(const Deque &rhs)
{
    if (rhs.count != 0) //if the deque is not empty
    {
        count = rhs.count;
        backi = rhs.backi;
        fronti = rhs.fronti;
        capacity = rhs.capacity; //copying the capacity of the rhs Deque

        items = new T[capacity]; //dequeue's size is of rhs's capacity

        if (rhs.backi < rhs.fronti) //if the back index is lesser than the front index (for rhs Dequeue)
        {
            int i = rhs.backi;
            while (i <= rhs.fronti)
            {
                items[i] = rhs.items[i];
                i++;
            }
        }
        else if (rhs.fronti < rhs.backi) //if the front index is lesser than the back index (for rhs Dequeue)
        {
            for (int j = 0; j <= fronti; j++)
            {
                items[j] = rhs.items[j];
            }

            for (int j = backi; j < capacity; j++) //copy values from the back index to the end
            {
                items[j] = rhs.items[j];
            }
        }
    }
    else
    {
        count = rhs.count;
        backi = rhs.backi;
        fronti = rhs.fronti;
        capacity = rhs.capacity; //copying the capacity of the rhs Deque
        items = new T[capacity]; //dequeue's size is of rhs's capacity
    }
}

//Copy-Assignment operator
template <typename T>
Deque<T> &Deque<T>::operator=(Deque<T> deq)
{
    //swap the values of this object with the passed object
    std::swap(items, deq.items);
    std::swap(capacity, deq.capacity);
    std::swap(fronti, deq.fronti);
    std::swap(backi, deq.backi);
    std::swap(count, deq.count);

    return *this;
}

// Method: Returns true if the deque is empty, else false
template <typename T>
bool Deque<T>::isEmpty() const noexcept
{
    if (count == 0)
        return true;
    else
        return false;
}

// Method: Add item to the front of the deque
// may throw std::bad_alloc
template <typename T>
void Deque<T>::pushFront(const T &item)
{
    //if adding an item to the front makes it full
    //We employ a double growth strategy
    if (count == capacity)
    {
        int old_capacity = capacity;
        capacity = capacity * GROWTH;

        T *new_items;

        try
        {
            new_items = new T[capacity]; //newly dynamically allocated array
        }
        catch (std::bad_alloc &bad) //throws std::bad_alloc if can't allocate space
        {
            std::cerr << "bad_alloc caught: " << bad.what() << std::endl;
        }

        if (backi < fronti)
        {
            int i = backi;
            while (i <= fronti)
            {
                new_items[i] = items[i];
                i++;
            }
        }
        else if (fronti < backi)
        {
            for (int j = 0; j <= fronti; j++)
            {
                new_items[j] = items[j];
            }

            for (int j = backi; j < old_capacity; j++)
            {
                new_items[old_capacity + j] = items[j];
            }

            backi = old_capacity + backi;
        }
        delete[] items; //deleting the previous array

        items = new_items; //items should point to the newly created array of items
        new_items = nullptr;

        delete[] new_items;

        new_items = nullptr;

        fronti++;

        items[fronti] = item;
        count++;
    }
    else if (fronti == -1) //the deque is empty when front is -1
    {
        fronti++;
        backi++;
        items[fronti] = item;
        count++;
    }
    else if (isEmpty()) //if the deque is empty and front is anywhere
    {
        if (fronti == capacity - 1) //if front is at the end
        {
            fronti = 0;
        }
        else
        {
            fronti++;
        }
        items[fronti] = item;
        count++;
    }
    else if (fronti == capacity - 1) //condition to employ wraparound effect
    {
        fronti = 0;
        items[fronti] = item;
        count++;
    }
    else
    {
        fronti++;
        items[fronti] = item;
        count++;
    }
}

// Method: Remove the item at the front of the deque
// throws std::runtime_error if the deque is empty
template <typename T>
void Deque<T>::popFront()
{
    if (isEmpty())
    {
        std::cout << "The Deque is empty!" << std::endl;
        throw std::runtime_error("Run Time Error because the Dequeue is empty!");
    }
    else if (fronti == 0)
    {
        fronti = capacity - 1;
        count--;
    }
    else
    {
        fronti--;
        count--;
    }
}

// Method: Returns the item at the front of the deque
// throws std::runtime_error if the deque is empty
template <typename T>
T Deque<T>::front() const
{

    std::cout << "The front index is: " << return_front_index() << std::endl;

    if (!isEmpty())
    {
        return items[fronti];
    }
    else
    {
        throw std::runtime_error("Run Time Error");
    }
}

// Method: Add item to the back of the deque
template <typename T>
void Deque<T>::pushBack(const T &item)
{
    //if adding an item to the back makes it full
    //We employ a double growth strategy
    if (count == capacity)
    {
        int old_capacity = capacity;
        capacity = capacity * GROWTH;

        T *new_items;

        try
        {
            new_items = new T[capacity]; //newly dynamically allocated array
        }
        catch (std::bad_alloc &bad) //throws std::bad_alloc if can't allocate space
        {
            std::cerr << "bad_alloc caught: " << bad.what() << std::endl;
        }

        if (backi < fronti)
        {
            for (int i = backi; i <= fronti; i++)
            {
                new_items[i] = items[i];
            }
        }
        else if (fronti < backi)
        {
            for (int j = 0; j <= fronti; j++)
            {
                new_items[j] = items[j];
            }

            for (int j = backi; j < old_capacity; j++)
            {
                new_items[old_capacity + j] = items[j];
            }
            backi = old_capacity + backi;
        }

        delete[] items; //deleting the previous array

        items = new_items; //items should point to the newly created array of items
        new_items = nullptr;

        delete[] new_items;
        new_items = nullptr;

        if (backi == 0)
        {
            backi = capacity - 1;
        }
        else
        {
            backi--;
        }

        items[backi] = item;
        count++;

        std::cout << std::endl;
        std::cout << "The element pushed to the back is: " << items[backi] << " at " << backi << std::endl;
        std::cout << std::endl;
    }
    else if (backi == -1) //the deque is empty when back is -1
    {
        backi = capacity - 1;
        fronti = backi;
        items[backi] = item;
        count++;
    }
    else if (backi == 0) //condition to employ wraparound effect
    {
        backi = capacity - 1;
        items[backi] = item;
        count++;
    }
    else
    {
        backi--;
        items[backi] = item;
        count++;
    }
}

// Method: Removes the item at the back of the deque
// throws std::runtime_error if the deque is empty
template <typename T>
void Deque<T>::popBack()
{
    if (isEmpty())
    {
        std::cout << "The Deque is empty!" << std::endl;
        throw std::runtime_error("Run Time Error");
    }
    else if (backi == capacity - 1)
    {
        backi = 0;
        count--;
    }
    else
    {
        backi++;
        count--;
    }
}

// Method: Returns the item at the back of the deque
// throws std::runtime_error if the deque is empty
template <typename T>
T Deque<T>::back() const
{
    std::cout << "The back index is: " << return_back_index() << std::endl;
    if (!isEmpty())
    {
        return items[backi];
    }
    else
    {
        throw std::runtime_error("Run Time Error");
    }
}

// // Method: Clears all entries in the double ended queue
// template <typename T>
// void Deque<T>::clear()
// {
//     delete[] items;

//     count = 0;

//     backi = -1;

//     fronti = -1;

//     items = new T[capacity];
// }

// // Method: Returns the number of items in the deque
// template <typename T>
// size_t Deque<T>::size() const
// {
//     std::cout << "The Count is: " << count << std::endl;
//     return count;
// }

// Private method: returns the back index
template <typename T>
int Deque<T>::return_back_index() const
{
    return backi;
}

// Private method: returns the front index
template <typename T>
int Deque<T>::return_front_index() const
{
    return fronti;
}