#ifndef TREAP_BST_HPP
#define TREAP_BST_HPP

#include <random>
#include <vector>

#include "abstract_bst.hpp"

template <typename KeyType, typename ValueType>
class TreapBST : public AbstractBST<KeyType, ValueType>
{
public:
    /** Default contructor. */
    TreapBST();

    /** Copy constructor. */
    TreapBST(const TreapBST &x);

    /** Copy-assignment. */
    TreapBST &operator=(TreapBST x);

    /** Destructor. */
    ~TreapBST();

    // method to determine if the treap is empty
    bool empty();

    // method to search for a key in the treap.
    ValueType search(const KeyType &key, bool &found);

    // method to insert a value into the treap with a unique key.
    void insert(const KeyType &key, const ValueType &value);

    // method to remove a value from the treap.
    void remove(const KeyType &key);

    /** Get the height of the treap. */
    std::size_t height();

private:
    /* Random number generator. */
    std::mt19937 rndgen;

    ValueType default_value;

    /* Node struct with key, data, random priority, and parent, left child, and right child pointers. */
    template <typename K, typename V>
    struct Node
    {
        K key;
        V data;
        std::mt19937::result_type priority;
        Node *childl;
        Node *childr;
        /* Random number generator. */
        std::mt19937 rndg;

        // default constructor
        Node(const K &k, const V &d)
            : key(k), data(d), childl(nullptr), childr(nullptr)
        {
            priority = rndg();
        }
    };

    // You may add private member variables/methods as needed.

    Node<KeyType, ValueType> *root; // pointer that will point to the root Node

    // std::vector<KeyType> key_values; // keeps track of existing key values

    // Left Rotation
    void rotateLeft(Node<KeyType, ValueType> *&ROOT);

    // Right rotation
    void rotateRight(Node<KeyType, ValueType> *&ROOT);

    // Private Method for Insertion of a new node to the Treap (recursive solution)
    void insert(const KeyType &key, const ValueType &value, Node<KeyType, ValueType> *&node);

    // Private Method for Deletion/Removal of any node of the Treap (recursive solution)
    void remove(const KeyType &key, Node<KeyType, ValueType> *&node);

    // Private Method for Searching a node within the Treap
    ValueType search(const KeyType &key, bool &found, Node<KeyType, ValueType> *&node);

    // Private Method for computing the height of a node of the Treap
    int height(Node<KeyType, ValueType> *&node);

    // Private method that makes a deep copy of another treap (used in the copy constructor)
    void copy(Node<KeyType, ValueType> *node);

    // Private method that clears the treap
    void clear(Node<KeyType, ValueType> *&node);
};

#include "treap_bst.txx"

#endif // TREAP_BST_HPP
