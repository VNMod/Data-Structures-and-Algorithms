#ifndef BOARDXO_HPP
#define BOARDXO_HPP

#include <iostream>
#include <string>

// A board struct for the game tic-tac-toe
struct BoardXO
{
   int8_t state[9];  //where player markers are on the board (player can be -1 or 1; 0 for unoccupied)
   uint8_t moves[9]; //sequence of moves that led to current game state (i.e., which marker position players selected)
   int8_t turn[9];   //which player made the corresponding move
   uint8_t numMoves; //total number of moves that have been made in the game to this point
   uint32_t id;      //a key (unique number) that one can assign to, and use to refer to, this particular board

   /* default constructor  
     @return a blank board (all positions unoccupied; i.e., 0 and numMoves = 0)*/
   BoardXO()
   {
      for (int i = 0; i < 9; i++) //all positions are unoccupied
      {
         state[i] = 0;
      }
      numMoves = 0; //no moves yet as blank board
      id = 0;
   }

   /* return marker for requested position
     @return the marker at the given position (-1, 0, 1) throw std::range_error if subscript is out of bounds*/
   const int8_t &operator[](std::uint8_t idx) const
   {
      //(state[idx] == -1 || state[idx] == 0 || state[idx] == 1) &&
      //state must be -1, 0 or 1 and position must be within the range of [0, 8]
      if (idx <= 8)
      {
         return state[idx];
      }
      else
      {
         throw std::range_error("The subscript is out of bounds");
      }
   }

   friend std::ostream &operator<<(std::ostream &os, const BoardXO &brd)
   {
      int row = 0;
      for (int i = 0; i < 9; i++) //out of the nine positions possible
      {
         if (row == 3)
         {
            row = 0;
            os << std::endl;
         }
         if (brd.state[i] == -1)
         {
            os << "X";
         }
         else if (brd.state[i] == 1)
         {
            os << "O";
         }
         else if (brd.state[i] == 0)
         {
            os << " ";
         }
         else
         {
            throw std::range_error("Subscript is out of bounds!");
         }
         row++;
      }

      os << std::endl;

      return os;
   }
};

#endif
