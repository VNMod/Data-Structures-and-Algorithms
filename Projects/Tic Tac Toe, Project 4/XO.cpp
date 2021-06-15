#include "XO.hpp"
#include "Deque.hpp"
#include <vector>

// Public Methods:

// Default Constructor: creates a blank game state
XO::XO()
{
}

// Parameterized Constructor: creates a game where moves have already been played
// Note: throws a std::logic_error and board remains blank if moves/players are invalid
XO::XO(const int8_t *play, const uint8_t *pos, const uint8_t &n)
{
  bool marked[9] = {false, false, false, false, false, false, false, false, false};
  bool exists[9] = {false, false, false, false, false, false, false, false, false};
  bool repeat_move = false;      //repeat flag for moves
  bool repeat_same_user = false; //repeat flag for same user

  b.numMoves = n; //assigning the same number of moves that have already been played (updating numMoves)

  for (int i = 0; i < n; i++) //checks for repeating moves
  {
    if (exists[pos[i]] == true) //if the same move already exists, then set repeat flag to true
    {
      repeat_move = true;
      break;
    }
    exists[pos[i]] = true;
  }

  for (int i = 0; i < n - 1; i++) //checks for repeating consecutive turns by same user
  {
    if (play[i] == -1)
    {
      if (play[i + 1] == -1)
      {
        repeat_same_user = true;
        break;
      }
    }
    else if (play[i] == 1)
    {
      if (play[i + 1] == 1)
      {
        repeat_same_user = true;
        break;
      }
    }
  }

  if (repeat_move)
  {
    throw std::logic_error("Illegal repeating moves");
  }
  else if (repeat_same_user)
  {
    throw std::logic_error("Multiple consecutive turns by same user! (not permitted)");
  }

  for (int i = 0; i < n; i++) //checking if the new moves/players are valid
  {
    if (play[i] != -1 && play[i] != 1) //turns can either be -1 or 1, but nothing else
    {
      throw std::logic_error("Invalid turns");
    }

    if (pos[i] >= 9) //positions must be within the range of [0-8]
    {
      throw std::logic_error("Positions are beyond range (0-8)!");
    }
  }

  for (int i = 0; i < n; i++)
  {
    b.turn[i] = play[i]; //assigning the turns that have already been played (updating turns)
    b.moves[i] = pos[i]; //assigning the moves that have already been played (updating moves)
    marked[b.moves[i]] = true;
  }

  for (int i = 0; i < 9; i++) //updating the board's states (updating states)
  {
    if (b.turn[i] == -1)
    {
      b.state[b.moves[i]] = -1;
    }
    else if (b.turn[i] == 1)
    {
      b.state[b.moves[i]] = 1;
    }
    else
    {
      if (marked[i] == false) //if a certain state hasn't been visited, state is 0
        b.state[i] = 0;
    }
  }
}

void XO::show()
{
  std::cout << b;
  std::cout << std::endl;
}

// Method: Places player marker play (-1 or 1) at position pos; increments number of moves counter (numMoves)
bool XO::makeMove(const int8_t &play, const uint8_t &pos)
{
  bool flag = false;

  bool exists[9] = {false, false, false, false, false, false, false, false, false};
  bool repeat_move = false; //repeat flag for moves

  for (int i = 0; i < b.numMoves; i++) //marking all pre-existing moves as 'exists' (true)
  {
    // std::cout << "moves: " << (int)b.moves[i] << std::endl;
    exists[b.moves[i]] = true;
  }

  if (exists[pos] == true) //if the same move already exists, then set repeat flag to true
  {
    // std::cout << "Problemo 2" << std::endl;
    // std::cout << "pos: " << (int)pos << std::endl;
    repeat_move = true;
  }

  // Rules to follow:
  // 1. Plays can be either -1 or 1
  // 2. Position of the marker can range from [0, 8]
  // 3. You should not be able to make a move when numMoves is 9 as the board has been filled out completely
  // 4. A game has not been won or drawn -> !gameOver()
  // 5. The state at that position hasn't been marked yet (so b.state[pos] == 0)
  // 6. No repeating turns (so previous turn was not played by the same player) -> b.turn[b.numMoves - 2] != play

  if ((play == 1 || play == -1) && pos <= 8 && pos >= 0 && b.numMoves < 9 && !gameOver() && b.state[pos] == 0 && !repeat_move)
  {
    if (b.numMoves >= 1 && b.turn[b.numMoves - 1] != play) //avoids a repeating turn
    {
      makeMove(play, pos, b);
      flag = true;
    }
    else if (b.numMoves == 0)
    {
      makeMove(play, pos, b);
      flag = true;
    }
  }

  return flag;
}

// Method: places multiple markers on the board
// game created that reflects moves specified by user; returns false and board is unmodified if moves/players are invalid
bool XO::makeMoves(const int8_t *play, const uint8_t *pos, const uint8_t &n)
{

  bool marked[9] = {false, false, false, false, false, false, false, false, false};
  bool exists[9] = {false, false, false, false, false, false, false, false, false};
  bool repeat_move = false;      //repeat flag for moves
  bool repeat_same_user = false; //repeat flag for same user

  if (b.numMoves + n > 9) //total number of moves (if these moves were made) are invalid
  {
    return false;
  }

  for (int i = 0; i < b.numMoves; i++) //marking all pre-existing moves as 'exists' (true)
  {
    exists[b.moves[i]] = true;
  }

  for (int i = 0; i < n; i++) //checks for repeating moves
  {
    if (exists[pos[i]] == true) //if the same move already exists, then set repeat flag to true
    {
      repeat_move = true;
      break;
    }
    exists[pos[i]] = true;
  }

  for (int i = 0; i < n - 1; i++) //checks for repeating consecutive turns by same user
  {
    if (play[i] == -1)
    {
      if (play[i + 1] == -1)
      {
        repeat_same_user = true;
        break;
      }
    }
    else if (play[i] == 1)
    {
      if (play[i + 1] == 1)
      {
        repeat_same_user = true;
        break;
      }
    }
  }

  if (repeat_move)
  {
    std::cout << "Illegal repeating moves" << std::endl;
    return false;
  }
  else if (repeat_same_user)
  {
    std::cout << "Multiple consecutive turns by same user! (not permitted)" << std::endl;
    return false;
  }

  for (int i = 0; i < n; i++) //checking if the new moves/players are valid
  {
    if (play[i] != -1 && play[i] != 1) //turns can either be -1 or 1, but nothing else
    {
      return false;
    }

    if (pos[i] >= 9) //positions must be within [0-9]
    {
      std::cout << "Positions is beyond range (0-8)!" << std::endl;
      return false;
    }
  }

  for (int i = 0; i < n; i++) //assigning the turns to be played (updating turns)
  {
    if ((play[i] == 1 || play[i] == -1) && pos[i] <= 8 && pos[i] >= 0 && b.numMoves < 9 && !gameOver() && b.state[pos[i]] == 0)
    {
      if ((b.numMoves >= 1 && b.turn[b.numMoves - 1] != play[i]) || b.numMoves == 0) //avoids a repeating turn
      {
        makeMove(play[i], pos[i]);
      }
      else
      {
        return false;
      }
    }
  }

  return true;
}

// Method: Pre-condition - board has one marker set (i.e., one player has placed a marker); post condition: game state updated to reflect optimal move for active player
bool XO::makeOptimalMove()
{
  if (b.numMoves == 0 || b.numMoves >= 9 || gameOver()) //pre-condition: board must have one marker set
  {
    return false;
  }

  Deque<BoardXO> q; //queues of BoardXOs

  int ID = 0;
  int final_score = 0; //final score
  int available_states = 0;
  Deque<int> right_most_index;
  right_most_index.pushBack(0); //add root node index (0)

  std::vector<BoardXO> visited(370000);
  std::vector<BoardXO> states(370000);

  std::vector<bool> visit_ID(370000, false);
  std::vector<int> parent(370000);
  std::vector<int> players_turn(370000, 0);
  parent[0] = 0;                  //the parent node of the root does not exist (so value is 0)
  std::vector<int> score(370000); //scores tree

  BoardXO cur_state;  //current state
  BoardXO game_state; //game state

  cur_state = getBoard(); //returning current state
  cur_state.id = ID;

  q.pushBack(cur_state); //enqueue the current state of the game to q

  int player; //current player (who must make the move)

  // std::cout << "NumMoves: " << (int)b.numMoves << std::endl;
  // std::cout << "Last Turn was by: " << (int)cur_state.turn[b.numMoves - 1] << std::endl;

  if ((int)b.numMoves > 0)
  {
    if (cur_state.turn[b.numMoves - 1] == 1)
    {
      player = -1;
      // players_turn[0] = 1;
    }
    else if (cur_state.turn[b.numMoves - 1] == -1)
    {
      player = 1;
      // players_turn[0] = -1;
    }
  }
  else
  {
    player = -1; // X begins by default (if first move)
  }

  players_turn[0] = player; //whose turn it is to perform the optimalMove

  // std::cout << "The player is: " << player << std::endl;

  while (!q.isEmpty())
  {
    // std::cout << "WHILE LOOP -- 1" << std::endl;

    // Explanation:
    // Root is represented by the current state
    // Its nodes are represented by the states of the game
    // Edges are represented by moves
    // Leaves are represented by final states (win, loss or draw)

    game_state = q.front(); //peek front value

    // std::cout << "ID of the current state: " << game_state.id << std::endl;

    q.popFront(); //pop the game state from the front of the q
    visit_ID[game_state.id] = true;
    visited[game_state.id] = game_state; //mark the game state as visited

    // marks exists at that position
    bool exists[9] = {false, false, false, false, false, false, false, false, false};

    for (int i = 0; i < game_state.numMoves; i++) //marking all pre-existing moves as 'exists' (true)
    {
      // std::cout << "FOR LOOP -- 1" << std::endl;
      exists[game_state.moves[i]] = true;
    }

    // exists[game_state.moves[game_state.numMoves - 1]] = true;
    // visited.push_back(true);

    //if(game state is terminal), marks score for the state (LEAVES/TERMINAL)
    if (game_state.numMoves == 9 || winner(game_state) == -1 || winner(game_state) == 1)
    {
      // std::cout << "TERMINAL/LEAF NODE" << std::endl;
      if (winner(game_state) == player) //if the player won
      {
        final_score = 10 - game_state.numMoves;
        score[game_state.id] = final_score;
      }
      else if (winner(game_state) != 0) //if the opponent won
      {
        final_score = game_state.numMoves - 10;
        score[game_state.id] = final_score;
      }
      else //in case of a draw
      {
        score[game_state.id] = 0;
      }

      right_most_index.pushFront(game_state.id); //finding the rightmost node
      //NOTE: after exiting the while loop, the right most index will be in front
    }
    //else, enqueue every possible state based on the available moves of the current player(enqueue all the possible moves for the player)
    else
    {
      Deque<int> next_possible_moves; //a queue that stores the next possible moves

      available_states = 9 - game_state.numMoves; //number of available states based on current moveset

      for (int i = 0; i < 9; i++)
      {
        // std::cout << "FOR LOOP -- 2" << std::endl;
        if (!exists[i])
        {
          // std::cout << "Possible Moves: " << i << std::endl;
          next_possible_moves.pushBack(i);
        }
      }

      //finding whose turn it is
      int user;
      if (game_state.numMoves > 0)
      {
        if (game_state.turn[game_state.numMoves - 1] == 1)
        {
          user = -1;
        }
        else if (game_state.turn[game_state.numMoves - 1] == -1)
        {
          user = 1;
        }
      }
      // else
      // {
      //   user = -1; //let X begin by default (when b.numMoves == 0)
      // }

      // std::cout << "The user is: " << user << std::endl;

      for (int i = 0; i < available_states; i++)
      {
        // std::cout << "FOR LOOP -- 3" << std::endl;

        int pos = next_possible_moves.front(); // peeking one of the possible moves

        // std::cout << "Position: " << pos << std::endl;

        next_possible_moves.popFront(); // popping it from its queue

        BoardXO new_state = game_state; //initialized with the current state

        // developing the new possible state
        new_state.moves[new_state.numMoves] = pos;
        new_state.turn[new_state.numMoves] = user;
        new_state.state[pos] = user;
        new_state.numMoves++;

        new_state.id = ID + 1; // new possible state takes a new incremented ID value
        ID++;                  //incrementing the ID value for particular node

        // std::cout << "state: " << std::endl;
        // std::cout << new_state.id << std::endl;
        // std::cout << "Number of moves: " << (int)new_state.numMoves << std::endl;
        // std::cout << "moves: " << std::endl;

        // for (int i = 0; i < new_state.numMoves; i++)
        // {
        //   std::cout << (int)new_state.moves[i] << std::endl;
        // }

        q.pushBack(new_state); //enqueue-ing this possible state

        //mark the parent vector indexed at the child node's ID as the value of the parent node's ID
        // ESTABLISHES A RELATION BETWEEN THE CHILD AND PARENT NODE
        parent[new_state.id] = game_state.id;

        states[new_state.id] = new_state;

        // std::cout << "New State ID: " << new_state.id << std::endl;

        players_turn[new_state.id] = user;
      }
    }
  }

  //end of creating the game tree (using Breadth First Search (BFS))
  //backing-up - SCORING EACH NODE APPROPRIATELY

  // remember: you maximize player's score
  // and minimize opponent's score

  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << std::endl;

  Deque<int> temp(right_most_index);

  while (!temp.isEmpty())
  {
    int c = temp.front();
    // std::cout << "Score for index " << c << ": " << score[c] << std::endl;
    // std::cout << "Parent of that index is " << parent[c] << std::endl;
    temp.popFront();
  }

  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << std::endl;
  // std::cout << std::endl;

  int max_move_index;
  int cur = right_most_index.front(); //peeking the front-most value
  right_most_index.popFront();

  while (cur != 0) //until you've reached the root node
  {
    // std::cout << "WHILE LOOP -- 2" << std::endl;

    // std::cout << "The Current Index is: " << cur << std::endl;

    // std::cout << "The current index's score is: " << score[cur] << std::endl;

    // REMEMBER: to write a for loop that compares for all the nodes of the same parent
    // REMEMBER: to pop all the child nodes for that parent

    int count = 0;

    // std::cout << "Parent[cur-1]: " << parent[cur - 1] << std::endl;
    // std::cout << "Parent[cur]: " << parent[cur] << std::endl;
    // std::cout << "comparison: " << (parent[cur - 1] == parent[cur]) << std::endl;

    for (int i = cur; (parent[i - 1] == parent[i]) && i != 0; i--) //find how many children nodes share the same parent (how many siblings)
    {
      // std::cout << "i: " << i << std::endl;
      // std::cout << "FOR LOOP -- 4" << std::endl;
      // std::cout << "parent[i]: " << parent[i] << std::endl;
      // std::cout << "score[i]: " << score[i] << std::endl;
      // std::cout << "comparison: " << (parent[i - 1] == parent[i]) << std::endl;
      count++;
    }

    score[parent[cur]] = score[cur];

    int factor;
    if (players_turn[cur] == player)
    {
      factor = 1; //minimizing factor for player
    }
    else
    {
      factor = -1; //maximizing factor for opponent
    }

    if (count != 0)
    {
      while (count != 0)
      {
        // std::cout << "cur: " << cur << std::endl;
        // std::cout << "Score[cur]]: " << score[cur] << std::endl;

        // std::cout << "WHILE LOOP -- 3" << std::endl;

        // std::cout << "parent[cur - 1] " << parent[cur - 1] << std::endl;
        // std::cout << "parent[cur] " << parent[cur] << std::endl;
        // std::cout << "parent[cur - 1] == parent[cur]: " << (parent[cur - 1] == parent[cur]) << std::endl;
        if (parent[cur - 1] == parent[cur]) //if a sibling node exists
        {
          // std::cout << "SIBLINGS" << std::endl;

          // std::cout << "players_turn[parent[cur]]: " << players_turn[parent[cur]] << std::endl;
          // std::cout << "player: " << player << std::endl;
          // std::cout << "players_turn[parent[cur]] == player: " << (players_turn[parent[cur]] == player) << std::endl;

          // if (players_turn[cur] == player) OR players_turn[parent[cur]] == player
          // {
          //   factor = 1;
          // }
          // else
          // {
          //   factor = -1;
          // }

          if (factor * score[cur] > factor * score[parent[cur]])
          {
            score[parent[cur]] = score[cur];
            // std::cout << "score[parent[cur]]: " << score[parent[cur]] << std::endl;
          }
        }

        cur--;
        count--;
      }
    }
    else
    {
      score[parent[cur]] = score[cur];
      cur--;
    }
  }

  // std::cout << "The Score of the root node: " << score[0] << std::endl;

  // std::cout << "Making the Optimal Move" << std::endl;

  int i = 0;
  while (parent[0] == parent[i])
  {
    if (score[0] == score[i])
    {
      // std::cout << "HERE" << std::endl;
      max_move_index = i;
    }
    i++;
  }

  // std::cout << "make moves" << std::endl;

  // std::cout << "max move: " << max_move_index << std::endl;

  //MAKING THE OPTIMAL MOVE:
  BoardXO optimalboard = states[max_move_index];

  // std::cout << "optimalboard.turn[optimalboard.numMoves-1]: " << (int)optimalboard.turn[optimalboard.numMoves - 1] << std::endl;
  // std::cout << "optimalboard.moves[optimalboard.numMoves-1]: " << (int)optimalboard.moves[optimalboard.numMoves - 1] << std::endl;

  // std::cout << "optimal state: " << std::endl;
  // std::cout << optimalboard.id << std::endl;
  // std::cout << "Number of moves: " << (int)optimalboard.numMoves << std::endl;
  // std::cout << "moves: " << std::endl;

  for (int i = 0; i < optimalboard.numMoves; i++)
  {
    std::cout << (int)optimalboard.moves[i] << std::endl;
  }

  int flag;
  flag = makeMove(optimalboard.turn[optimalboard.numMoves - 1], optimalboard.moves[optimalboard.numMoves - 1]);

  return flag;
}

// Method: returns current board (this is mainly for testing/grading)
BoardXO XO::getBoard()
{
  return b;
}

// Method: 1 draw or game won, 0 available moves
bool XO::gameOver()
{
  return gameOver(b);
}

// Method: -1 for player -1 or 1 for player 1 or 0 for no winner (draw)
int8_t XO::winner()
{
  return winner(b);
}

// Private Methods:

// Method: 1 draw or game won, 0 available moves
bool XO::gameOver(const BoardXO &brd)
{
  bool game_won = false;
  bool available_moves = true;

  if (brd.numMoves >= 9) //0 available moves
  {
    available_moves = false;
  }

  if (winner(brd) == -1 || winner(brd) == 1) //if a winner exists or in case of a draw
    game_won = true;
  else
    game_won = false;

  return (game_won || !available_moves);
}

// Method: -1 for player -1 or 1 for player 1 or 0 for no winner (draw)
int8_t XO::winner(const BoardXO &brd)
{
  int8_t winner;

  if (brd.state[0] == brd.state[1] && brd.state[1] == brd.state[2]) //horizontal case 1 (top row)
  {
    winner = brd.state[0];
  }
  else if (brd.state[3] == brd.state[4] && brd.state[4] == brd.state[5]) //horizontal case 2 (middle row)
  {
    winner = brd.state[3];
  }
  else if (brd.state[6] == brd.state[7] && brd.state[7] == brd.state[8]) //horizontal case 3 (bottom row)
  {
    winner = brd.state[6];
  }
  else if (brd.state[0] == brd.state[3] && brd.state[3] == brd.state[6]) //vertical case 1 (left column)
  {
    winner = brd.state[0];
  }
  else if (brd.state[1] == brd.state[4] && brd.state[4] == brd.state[7]) //vertical case 2 (middle column)
  {
    winner = brd.state[1];
  }
  else if (brd.state[2] == brd.state[5] && brd.state[5] == brd.state[8]) //vertical case 3 (right column)
  {
    winner = brd.state[2];
  }
  else if (brd.state[0] == brd.state[4] && brd.state[4] == brd.state[8]) //Diagonal case 1 covering indices 0, 4, 8
  {
    winner = brd.state[0];
  }
  else if (brd.state[2] == brd.state[4] && brd.state[4] == brd.state[6]) //Diagonal case 2 covering indices 2, 4, 6
  {
    winner = brd.state[2];
  }
  else //draw
  {
    winner = 0;
  }

  return winner;
}

// Method: 1 draw or game won, 0 available moves
void XO::makeMove(const int8_t &play, const uint8_t &pos, BoardXO &brd)
{
  brd.state[pos] = play;         //placing player's marker play at position pos
  brd.moves[brd.numMoves] = pos; //updating new position in list of moves
  brd.turn[brd.numMoves] = play; //updating the current turn value on new move
  brd.numMoves++;                //incrementing the moves counter as a move was just made
}

// void XO::return_states()
// {
//   std::cout << "States: " << std::endl;
//   for (int i = 0; i < b.numMoves; i++)
//   {
//     std::cout << (int)b.state[i] << std::endl;
//   }
// }
// void XO::return_moves()
// {
//   std::cout << "Moves: " << std::endl;
//   for (int i = 0; i < b.numMoves; i++)
//   {
//     std::cout << (int)b.moves[i] << std::endl;
//   }
// }
// void XO::return_turns()
// {
//   std::cout << "Turns: " << std::endl;
//   for (int i = 0; i < b.numMoves; i++)
//   {
//     std::cout << (int)b.turn[i] << std::endl;
//   }
// }
// void XO::return_numMoves()
// {
//   std::cout << "Number of Moves: " << (int)b.numMoves << std::endl;
// }
// void XO::return_id()
// {
//   std::cout << "Board ID: " << b.id << std::endl;
// }