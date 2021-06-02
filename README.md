# Data-Structures-and-Algorithms

This repository contains:

- the Abstract Data Type (ADT) implementations for various data structures: [Double Linked List](https://github.com/VNMod/Data-Structures-and-Algorithms/tree/main/Data%20Structures/Double%20Linked%20List%20ADT), [Stacks](https://github.com/VNMod/Data-Structures-and-Algorithms/tree/main/Data%20Structures/Stack%20ADT), [Double Ended Queues](https://github.com/VNMod/Data-Structures-and-Algorithms/tree/main/Data%20Structures/Double%20Ended%20Queue%20ADT) and [Treaps (Heap Trees)](https://github.com/VNMod/Data-Structures-and-Algorithms/tree/main/Data%20Structures/Treap%20ADT).
- They were written as per the requirements for Virginia Tech's (ECE2564) Data Structure &amp; Algorithms class projects.
- a list of projects that implement popular algorithms and the above mentioned ADTs.

## Running the files using CMake (on Mac)

- Add CMake to the path variable by running the following command in the Terminal:
  ```
  PATH="/Applications/CMake.app/Contents/bin":"$PATH
  ```
  
- Then, generate the build and configuration files (it uses the CMakeLists.txt file that enlists the the source, targets and executables) with this command:

  ```
  cmake .
  ```
  
- This should create all the necessary configuration files and the executable. Each ADT should have a "unittests.cpp" file that tests the ADT and by running the   ```make``` command, the executable for this "unittests" file is created.

- Then run the generated executable. So, you should technically be running ```./unittests```. This runs and checks if all the unit test cases have passed as required.
