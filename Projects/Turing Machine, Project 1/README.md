# turing-machine

### Date: September 2020

## Task:

This program simulates a simple Turing Machine that solves a particuar algorithm.

## Criteria:

* Using a Double Linked List [implemented here](https://github.com/VNMod/Data-Structures-and-Algorithms/tree/main/Data%20Structures/Double%20Linked%20List%20ADT) to create a tape consisting of blank cells that may possibly contain symbols.
* Creating a pattern match algorithm that then allows the machine to (over)write a symbol to a cell, move the tape left or right by one cell at a time without counters/sums or additional programming tricks (but while loops and if statements are permitted).

## Important Aspects and Limitations:

### General Overview:

It consists of:

- a tape (potentially of infinite length) consisting of cells that can be blank or contain a symbol (one symbol per cell).
- an algorithm

Note: Turing Machines do not have any extra memory to keep a counter or do sum operations, etc.

### Tape:

The key operations on a tape are:

- Move Right
- Move Left
- Read Symbol
- Write Symbol

The Tape class (in Tape.hpp, Tape.cpp) support:

- a default constructor that creates an empty tape
- a construction of a tape initialized with symbols in its cells (one cell per symbol) • a copy constructor
- a destructor
- a method to get the number of cells in the tape
- a method to get the current cell, i.e., where the head currently points to
- a method to set the tape content
- a method to determine if the tape is empty
- a method to move the head right by one cell
- a method to move the head left by one cell
- a method to write a blank symbol to the current cell
- a method to write a specified symbol to the current cell • method to read the symbol from the current cell
- a method to clear the tape, i.e., make it empty
- a method to print out the content of the tape
- a method to rewind the tape to the first cell

### Turing Machine:

The Turing Machine class support:

- a default constructor that creates an empty Turing machine, i.e., empty tape and empty list of legal
symbols
- a parameterized constructor
- a destructor
- a method to get the list of legal symbols
- a method to get the tape
- a method to set the list of legal symbols
- a method to set the tape
- a method to reset the machine, i.e., empty tape and empty list of legal symbols • method to check if the setup is legal (see below)
- a methods to match pattern (see below)

### Pattern Match:

  - The Turing Machine's tape consists of a set of legal symbols: {a, b, c}
  - The pattern match algorithm must be able to check whether the tape follows the *a<sup> i</sup> b<sup> j</sup> c<sup> j</sup>* pattern, where i, j >= 1 and are integers.
  - However, this pattern match algorithm must happen using only tape operations.

    #### Examples:
    - Example 1: tape = {a b c} is a match as i = 1, j = 1
    - Example 2: tape = {a b b c c} is a match as i = 1, j = 2
    - Example 3: tape = {a b c c} is not a match as number of bs is not equal to the number of cs
    - Example 4: tape = {b b c c} is not a match as i = 0
    - Example 5: tape = {a b c a b c} is not a match as it doesn't match the *a<sup>i</sup>b<sup>j</sup>c<sup>j</sup>* pattern.

    #### Algorithm:
    
    For example, let's take:   ```{a b b c c}```
    
    1. Check if first symbol is *a*. If not, then return false.

    - ```{>a b b c c}``` passes this. 

    2. If this is true, move right as long as the current index is always lesser than the (tape size - 1).
    3. Now once all the *a* symbols have been encountered, check if the first symbol encoountered is a *b*.

    - ```{a >b b c c}``` passes this. 
   
    4. If it's a *b*, then write an *X* symbol in place and move right. If not, then return false.

    - ```{a >b b c c}``` becomes ```{a >X b c c}```. 
   
    5. This cell should now either be a *b* or *c*. If not, then return false.

    - ```{a X >b c c}``` passes this. 

    6. While the current symbols are either *b* or *c* and the current index is always lesser than the (tape size - 1), move right and return false if any other characters are encountered.

    - So, you get ```{a X b c >c}```.

    8. Now, if the current symbol is a *c*, then write a *Y* symbol in place and move right. If not, then return false.

    - ```{a X b c >c}``` becomes ```{a X b c >Y}```. 

    8. Now, move left till you don't encounter an *X*.

    - You're at X like this: ```{a >X b c Y}```.

    9. Then, move right and check if the symbol is either a *b* or *c*. If not, then *the pattern successfully matches*. 

    - Since ```{a X >b c Y}``` shows that we've encountered a *b* we move on.

    10. Else if it is a *b* symbol, then overwrite an *X* and keep moving right till you encounter a Y symbol. If it's not a *b*, then return false.

    - You overwrite to get: ```{a X >X c Y}```
    - Then move right till you're at Y: ```{a X X c >Y}```

    11. Now, move left and overwrite a *Y* symbol if it priorly contained a *c* symbol. If not, then return false.

    - You move left and overwrite since there's a *c*. So, ```{a X X >c Y}``` becomes ```{a X X >Y Y}```

    12. Repeat steps (viii to xi) till either the pattern successfully matches or false is definitively returned.

    Now, on repeating steps viii to xi you get the following:
    - Move left till you encounter X: ```{a X >X Y Y}```
    - Now, move right and check if the symbol is either a *b* or *c*: ```{a X X >Y Y}```
    - Since the machine head points to neither a *b* or *c*, *the pattern successfully matches*.


### Running it locally (on the Mac Terminal):

- Add CMake to the path variable by running the following command in the Terminal:
  ```
  PATH="/Applications/CMake.app/Contents/bin":"$PATH
  ```
  
- Then, generate the build and configuration files (it uses the CMakeLists.txt file that enlists the source, targets and executables) with this command:

  ```
  cmake .
  ```
  
- This should create all the necessary configuration files and the executable. This project should have a **unittests.cpp** file that contains the unit test cases for all the methods and by running the   ```make``` command, the executable for this **unittests.cpp** file is created.

- Then run the generated executable. You run the detect executable as follows:

  ```
  ./unittests
  ```
  
  
