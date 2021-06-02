#include "treap_bst.hpp"

#include <algorithm>
#include <stack>
#include <stdexcept>
#include <iostream>

// Default Constructor
template <typename KeyType, typename ValueType>
TreapBST<KeyType, ValueType>::TreapBST() : root(nullptr)
{
  //produces non-deterministic random numbers
  std::random_device rd;

  //seeds the std::mt19937 random number engine with a random 32-bit value
  rndgen.seed(rd());
}

// The rest of my code here:

// Copy Constructor
template <typename KeyType, typename ValueType>
TreapBST<KeyType, ValueType>::TreapBST(const TreapBST &x)
{
  if (x.root != nullptr) //if Treap x is not empty, then perform the deep copy
  {
    //clear, then copy
    root = nullptr;
    copy(x.root);
  }
  else //if x is an empty Treap
  {
    root = nullptr; //else default assignment of root pointer to nullptr
  }
}

// private method responsible for clearing the Treap
template <typename KeyType, typename ValueType>
void TreapBST<KeyType, ValueType>::clear(Node<KeyType, ValueType> *&node)
{
  if (node != nullptr)
  {
    //delete both the subtrees
    clear(node->childl);
    clear(node->childr);

    delete node;
    node = nullptr;
  }
}

// private method responsible for making deep copies (called in copy constructor)
template <typename KeyType, typename ValueType>
void TreapBST<KeyType, ValueType>::copy(Node<KeyType, ValueType> *node)
{
  if (node != nullptr) //if the node exists
  {
    insert(node->key, node->data);

    copy(node->childl);
    copy(node->childr);
  }
}

// Copy-Assignment (operator overloading => (deep) copies over all data from the user passed Treap x)
template <typename KeyType, typename ValueType>
TreapBST<KeyType, ValueType> &TreapBST<KeyType, ValueType>::operator=(TreapBST x)
{
  if (root == nullptr)
  {
    copy(x.root);
  }
  else
  {
    clear(root); //clear the root first
    root = nullptr;
    copy(x.root); //then copy the values over
  }

  return *this; //return this object
}

// Destructor - clears the whole Treap by invoking the private method clear()
template <typename KeyType, typename ValueType>
TreapBST<KeyType, ValueType>::~TreapBST()
{
  clear(root);
}

// returns whether a Treap is empty
template <typename KeyType, typename ValueType>
bool TreapBST<KeyType, ValueType>::empty()
{
  bool isEmpty;

  if (root == nullptr)
  {
    isEmpty = true;
  }
  else
  {
    isEmpty = false;
  }

  return isEmpty;
}

// method to search for a key in the treap.
template <typename KeyType, typename ValueType>
ValueType TreapBST<KeyType, ValueType>::search(const KeyType &key, bool &found)
{
  if (empty())
  {
    found = false;
    std::cout << "Invalid search as the Treap is empty!" << std::endl;
    return default_value;
  }
  else
  {
    return search(key, found, root); //value = search(key, found, root);
  }
}

// method that performs a search across the Treap to find the node by the user specified key
// a boolean variable called found is passed by reference and is assigned true if the node was found, and false otherwise.
template <typename KeyType, typename ValueType>
ValueType TreapBST<KeyType, ValueType>::search(const KeyType &key, bool &found, Node<KeyType, ValueType> *&node)
{
  if (node == nullptr)
  {
    found = false;
    return default_value;
  }
  else if (node->key == key)
  {
    found = true;
    return node->data; //return the data value for that node
  }
  //if the key of the value to be found is lesser than that node's key
  //recursively search the left subtree
  else if (key < node->key)
  {
    //bool flag = false;
    return search(key, found, node->childl);
  }
  //else the key of the value to be found is greater than that node's key.
  //so, recursively search the right subtree
  else
  {
    //bool flag = false;
    return search(key, found, node->childr);
  }
}

// method that calls the private insert method insert() to insert a node with the user provided key and data value
template <typename KeyType, typename ValueType>
void TreapBST<KeyType, ValueType>::insert(const KeyType &key, const ValueType &value)
{
  insert(key, value, root);
}

// private method that inserts a value into the treap with the user specified (unique) key and data value.
// a std::logic_error is thrown if the user passed key already exists
template <typename KeyType, typename ValueType>
void TreapBST<KeyType, ValueType>::insert(const KeyType &key, const ValueType &value, Node<KeyType, ValueType> *&p_node)
{
  if (p_node == nullptr) //base case
  {
    p_node = new Node<KeyType, ValueType>(key, value);
  }
  else if (key == p_node->key) // non-unique key
  {
    throw std::logic_error("Key already exists in this Treap!");
  }
  else if (key < p_node->key) //if the key is smaller than that of the p_node
  {
    // insert in the left subtree of the p_node
    insert(key, value, p_node->childl);

    // rotate right if the priority of the p_node's left child is greater than its p_node's
    if (p_node->childl != nullptr && p_node->childl->priority > p_node->priority)
    {
      rotateRight(p_node);
    }
  }
  else //if the key is greater than the root
  {
    // insert in the right subtree of the p_node
    insert(key, value, p_node->childr);

    // rotate left if the priority of the p_node's right child is greater than its p_node's
    if (p_node->childr != nullptr && p_node->childr->priority > p_node->priority)
    {
      rotateLeft(p_node);
    }
  }
}

// method to facilitate left rotation along a node
template <typename KeyType, typename ValueType>
void TreapBST<KeyType, ValueType>::rotateLeft(Node<KeyType, ValueType> *&X)
{
  // X is the relative root node (here)

  /*

     X
    / \
   A   Y
      / \
     B   C

  */

  // gets converted into (after rotating left)

  /*

     Y
    / \
   X   C
  / \
 A   B

  */

  Node<KeyType, ValueType> *B = X->childl->childr;
  Node<KeyType, ValueType> *Y = X->childr;

  Y->childl = X;
  X->childr = B;

  X = Y; // Y is now the new root node
}

// method to facilitate right rotation along a node
template <typename KeyType, typename ValueType>
void TreapBST<KeyType, ValueType>::rotateRight(Node<KeyType, ValueType> *&Y)
{
  // Y is the relative root node (here)

  /*

     Y
    / \
   X   C
  / \
 A   B

  */

  // gets converted into (after rotating right)

  /*

     X
    / \
   A   Y
      / \
     B   C

  */

  Node<KeyType, ValueType> *B = Y->childl->childr;
  Node<KeyType, ValueType> *X = Y->childl;

  X->childr = Y;
  Y->childl = B;

  Y = X; // X is now the new root node
}

// method to perform the private remove() method for successful removal of a node from the treap as per the provided key.
// a std::logic_error is thrown if the user provided key shows no match to any node of the Treap
template <typename KeyType, typename ValueType>
void TreapBST<KeyType, ValueType>::remove(const KeyType &key)
{
  if (empty())
  {
    std::cout << "The treap is empty! Unable to remove. " << std::endl;
    throw std::logic_error("Treap is empty!");
  }
  else
  {
    remove(key, root);
  }
}

// method to perform the removal of a node from the treap as per the provided key
template <typename KeyType, typename ValueType>
void TreapBST<KeyType, ValueType>::remove(const KeyType &key, Node<KeyType, ValueType> *&node)
{
  if (root == nullptr) //base case: key does not exist
  {
    return;
  }

  //if the key is lesser than the key of that node, recur for left subtree
  if (key < node->key)
  {
    remove(key, node->childl);
  }
  //if the key is greater than the key of that node, recur for right subtree
  else if (key > node->key)
  {
    remove(key, node->childr);
  }
  else // when the keys match (or key is found)
  {
    //Case 1:
    //if the node to be deleted is a LEAF node
    //it's easy to delete (simply delete the node)
    if (node->childl == nullptr && node->childr == nullptr)
    {
      delete node;
      node = nullptr;
    }
    //Case 2:
    //if the node to be deleted has two children
    //it gets a little complicated to delete that node (recursive solution with rotations)
    else if (node->childl && node->childr)
    {
      if (node->childl->priority < node->childr->priority)
      {
        rotateLeft(node);
        //recursively allows us to rotate keeping priorities in check
        //until either the node is rotated to be a leaf node or a node with one child
        //so that it can be easily removed!
        remove(key, node->childl);
      }
      else
      {
        rotateRight(node);
        //recursively allows us to rotate keeping priorities in check
        //until either the node is rotated to be a leaf node or a node with one child
        //so that it can be easily removed!
        remove(key, node->childr);
      }
    }
    //Case 3:
    //if the node to be deleted only has one child node
    else
    {
      Node<KeyType, ValueType> *child = nullptr;
      if (node->childr == nullptr) //if the left child exists
      {
        child = node->childl;
      }
      else if (node->childl == nullptr) //else if the right child exists
      {
        child = node->childr;
      }

      Node<KeyType, ValueType> *currNode = node; //currNode points to the node to be deleted
      node = child;                              //now, making the child node the root node
      delete currNode;                           //deletes the desired node since linkage with that node was broken
      currNode = nullptr;
    }
  }
}

// method to return the height of the treap.
template <typename KeyType, typename ValueType>
std::size_t TreapBST<KeyType, ValueType>::height()
{
  size_t Height;

  if (empty()) //if the Treap is empty
  {
    Height = 0; //height is 0
  }
  else
  {
    Height = height(root); //finding the height from the root of the treap
  }

  return Height;
}

// method to calculate the height of the treap
template <typename KeyType, typename ValueType>
int TreapBST<KeyType, ValueType>::height(Node<KeyType, ValueType> *&node)
{
  //depth of a leaf node is 0.
  //after returning, the values go either to leftHeight or rightHeight
  //the maximum of the two heights (plus one) is returned.
  //this is done multiple times until the height of the 2 subtrees of the root have been calculated
  //and the greater of the two heights (plus one) is returned to be the height value.

  if (node == nullptr) //for leaf node -- base case
  {
    return 0;
  }

  // Computing the height of each subtree
  std::size_t leftHeight = height(node->childl);
  std::size_t rightHeight = height(node->childr);

  if (leftHeight > rightHeight)
  {
    return (leftHeight + 1);
  }
  else
  {
    return (rightHeight + 1);
  }
}