# tic_tac_toe_solver

### Date: October 2020

## Task:

This program stores all the viruses written down in a .txt file (here, db.txt) and then determines if a given binary file contains any of these viruses/malware.

## Criteria:

* Using a Deque ADT [implemented here](https://github.com/VNMod/Data-Structures-and-Algorithms/tree/main/Data%20Structures/Double%20Ended%20Queue%20ADT) to create a class that plays Tic Tac Toe (X's and O's) optimally.
* Using a popular game thory approach/strategy called minimax to solve the game.


## Important Aspects and Limitations:

### Minimax Algorithm:

The minimax algorithm requires that we:
1. Enumerate every possible game state based on available moves
2. Follow a backing-up procedure to determine which move should be made at a given turn.

#### Breadth-First Search (BFS)

- Create the game tree using breadth-first search (BFS) on a queue/deque.
- The algorithm for the same is:
  1. q is a double-ended queue/deque, 
  2. enqueue the current state of the game to q, 
  3. while q is not empty,
  a. pop the game state from the front of the q, 
  b. mark the game state as visited, 
  c. if the game state is terminal (i.e. results in the game ending) mark the score for the state, 
  d. else enqueue every possible state based on the available moves of the current player (i.e. enqueue all the possible moves for the player)


### BoardXO:

- A struct called BoardXO consists of the following:
1. int8_t state[9]: the current state of the game; i.e., where X and O have placed their markers. 0 denotes no marker has been placed in that position.
2. uint8_t moves[9]: the position selected by the player for the 0th, 1st, 2nd, 3rd, etc. move
3. int8_t turn[9]: the player responsible for the 0th, 1st, 2nd, 3rd, etc. move.
4. uint8_t numMoves: the number of moves that have been made in the game
5. uint32_t id: a key (unique number) that one can assign to, and use to refer to, this particular board

- It is essentially represtative of a game state.

### XO (the Game):

- The XO class keeps track of the state of the game.

### Scoring Strategy:

In order to reward game states that use the fewest turns to achieve wins we use the following strategy:

1. if the player wins: the score is 10 - the total number of moves
2. if the opponent wins: the score is total number of moves - 10


### Running it locally (on the Mac Terminal):

- Add CMake to the path variable by running the following command in the Terminal:
  ```
  PATH="/Applications/CMake.app/Contents/bin":"$PATH
  ```
  
- Then, generate the build and configuration files (it uses the CMakeLists.txt file that enlists the source, targets and executables) with this command:

  ```
  cmake .
  ```
  
- This should create all the necessary configuration files and the executable. This project should have a **unittests.cpp** file that detects the viruses and by running the   ```make``` command, the executable for this **unittests.cpp** file is created.

- Then run the generated executable. You run the detect executable as follows:

  ```
  ./unittests
  ```
  
  
