# virus_detector

### Date: December 2020

## Task:

This program stores all the viruses written down in a .txt file (here, db.txt) and then determines if a given binary file contains any of these viruses/malware.

## Criteria:

* Implementing a Treap and BST (**Binary Search Trees**) ADT and using it to store a list of known viruses.
* Appropriately parsing through a binary file for viruses and reporting them, if any.


## Important Aspects and Limitations:

### Database (.txt file):
- The .txt file (here, db.txt) stores a virus/malware per line and is expressed as a binary string with a variable number of bytes. For example, 10010110 would denote a virus of one byte.
- This database file can only contain three viruses. However, their sizes do not matter and can be changed.
- The viruses are stored in a treap (**or tree heap**) by the program.
- The code and implementation for this can be found in the **detect.cpp** file.

### Infected binary file (.dat file):
- The .dat file (here, sample.dat) contains several bytes of data, and may contain several viruses.
- This program reports any detected instances of the viruses as stored within the **treap**.
- If no viruses have been found, then the program prints out: No viruses/malware found!
- The code and implementation for this can be found in the **detect.cpp** file.

### Implementing the Treap (Tree Heap) Data Structure:
- Treaps are a type of self-balancing trees called heaps that balance themselves on the basis of randomly generated priority values via transformations/rotations. 
- They're also binary search trees and thus left and right subtrees of each node must be binary search trees. The distinctive property of a binary search tree is that the left subtree of a node must only contain nodes with keys lesser than that node's key AND the right subtree must only contain nodes with keys greater than that node's key.
- Thus each node within a treap has three associated properties: key, value and priority. In summary, **keys are for maintaining BST properties** and **priorities are for maintaining max Heap properties**. **Value is the actual data to be stored in a node**.
- The implemented Treap ADT allows a user to check if a Treap is empty, to search for a particular key and the associated node, to insert a node, to remove a node and obtain the height of a treap.
- The detailed code and implementation can be found in the **treap_bst.txx** file.

### Running it locally:
