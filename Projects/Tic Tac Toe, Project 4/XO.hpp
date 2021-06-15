#ifndef XO_HPP
#define XO_HPP

#include <iostream>

#include "BoardXO.hpp"

class XO
{
private:
  BoardXO b; //a board that stores the current state of the game
  //optional but helpful for makeOptimalMove:
  bool gameOver(const BoardXO &brd);                                   //1 draw or game won, 0 available moves
  int8_t winner(const BoardXO &brd);                                   //-1 for player -1 or 1 for player 1 or 0 for no winner (draw)
  void makeMove(const int8_t &play, const uint8_t &pos, BoardXO &brd); //1 draw or game won, 0 available move

public:
  /* default constructor  
     @return blank game state*/
  XO();

  /* create game where moves have already been played
     @return game created that reflects moves specified by user; throws a std::logic_error and board remains blank if moves/players are invalid */
  XO(const int8_t *play, const uint8_t *pos, const uint8_t &n);

  void show();

  bool makeMove(const int8_t &play, const uint8_t &pos); //place player marker play (-1 or 1) at position pos; increment number of moves counter (numMoves)

  /* place multiple markers on the board
     @return game created that reflects moves specified by user; returns false and board is unmodified if moves/players are invalid */
  bool makeMoves(const int8_t *play, const uint8_t *pos, const uint8_t &n);

  bool makeOptimalMove(); // pre-condition: board has one marker set (i.e., one player has placed a marker); post condition: game state updated to reflect optimal move for active player

  BoardXO getBoard(); //return current board (this is mainly for testing/grading)

  bool gameOver(); //1 draw or game won, 0 available moves

  int8_t winner(); //-1 for player -1 or 1 for player 1 or 0 for no winner (draw)

  //for testing purposes:
  // void return_states();
  // void return_moves();
  // void return_turns();
  // void return_numMoves();
  // void return_id();
};

#endif
