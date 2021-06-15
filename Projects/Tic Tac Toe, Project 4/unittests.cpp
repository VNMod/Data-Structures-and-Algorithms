#include "catch.hpp"
#include "XO.hpp"

// TEST_CASE("Default Constructor for BoardXO", "[BoardXO]")
// {
//   XO game;
//   BoardXO b;
//   b = game.getBoard();

//   for (int i = 0; i < 9; i++) //all positions are unoccupied for this game (by default)
//   {
//     REQUIRE(b[i] == 0);
//   }
// }

// TEST_CASE("Testing makeMove() and winner() for XO", "[XO]")
// {
//   XO game;
//   BoardXO b = game.getBoard();
//   game.makeMove(-1, 0); //legal move

//   // game.show();

//   // std::cout << std::endl;

//   game.makeMove(1, 1); //legal move

//   // game.show();

//   // std::cout << std::endl;

//   REQUIRE_FALSE(game.makeMove(-1, 1)); //illegal move: as position is occupied

//   REQUIRE_FALSE(game.makeMove(1, 3)); // illegal move: as same player went twice (consecutively)

//   game.makeMove(-1, 7);

//   REQUIRE_FALSE(game.makeMove(1, 9));  // illegal move: position is invalid as range [0, 8]
//   REQUIRE_FALSE(game.makeMove(1, -6)); // illegal move: position is invalid as range [0, 8]

//   // game.show();

//   // std::cout << std::endl;

//   game.makeMove(1, 4);
//   game.makeMove(-1, 3);
//   game.makeMove(1, 8);
//   game.makeMove(-1, 6);

//   // game.show();

//   // std::cout << std::endl;

//   // By NOW, game board should be:
//   /*

//   X0
//   X0
//   XX0

//   which entails that X has won (or player -1).

//   */

//   REQUIRE(game.winner() == -1); //as X should have won

//   REQUIRE_FALSE(game.makeMove(1, 5)); // illegal move: game is over as X already won
// }

// TEST_CASE("Testing makeMoves() and winner() for XO", "[XO]")
// {
//   XO game;
//   game.makeMove(-1, 0); //legal move

//   // game.return_states();
//   // std::cout << std::endl;
//   // game.return_moves();
//   // std::cout << std::endl;
//   // game.return_turns();
//   // std::cout << std::endl;

//   // game.show();

//   // std::cout << std::endl;

//   const int8_t play1[4] = {1, -1, 1, -1};
//   const uint8_t pos1[4] = {1, 2, 3, 4};
//   const uint8_t size1 = 4;

//   game.makeMoves(play1, pos1, size1); //legal parameters

//   // game.show();

//   const int8_t play2[2] = {1, -1};
//   const uint8_t pos2[2] = {6, 5};
//   const uint8_t size2 = 2;
//   const uint8_t size3 = 3;

//   // game.return_states();
//   // std::cout << std::endl;
//   // game.return_moves();
//   // std::cout << std::endl;
//   // game.return_turns();
//   // std::cout << std::endl;

//   REQUIRE_FALSE(game.makeMoves(play1, pos1, size1)); //illegal parameters - repeating positions 1, 2, 3 and 4
//   REQUIRE_FALSE(game.makeMoves(play2, pos2, size3)); //illegal parameters - size of play2 and pos2 is not equal to the value of size3
//   REQUIRE(game.makeMoves(play2, pos2, size2));

//   // game.return_states();
//   // std::cout << std::endl;
//   // game.return_moves();
//   // std::cout << std::endl;
//   // game.return_turns();
//   // std::cout << std::endl;

//   // game.show();

//   const int8_t play3[3] = {1, -1, 1};
//   const uint8_t pos3[3] = {7, 8, 9};

//   REQUIRE_FALSE(game.makeMoves(play3, pos3, size3)); //illegal parameter - as game is over after 2 more plays (max 9 plays)
//   REQUIRE(game.winner() == 0);
//   REQUIRE(!game.gameOver());

//   const int8_t play4[2] = {-1, 1};
//   const int8_t play5[2] = {1, -1};
//   const uint8_t pos4[2] = {7, 8};

//   REQUIRE_FALSE(game.makeMoves(play4, pos4, size2)); //illegal parameter - repeating turn for player -1
//   REQUIRE(game.makeMoves(play5, pos4, size2));       //legal parameter - as player 1 starts this turn now

//   // game.show();

//   REQUIRE(game.gameOver());
//   REQUIRE(game.winner() == -1);
// }

// TEST_CASE("Testing makeOptimalMove() for XO (Test 1)", "[XO]")
// {
//   int8_t play[] = {-1, 1, -1, 1, -1, 1, -1};
//   uint8_t pos[] = {2, 0, 3, 4, 7, 6, 5};

//   XO game(play, pos, 7);

//   game.show();

//   REQUIRE(game.makeOptimalMove());

//   game.show();
// }

// TEST_CASE("Guessing instructor tests for makeOptimalMove() for XO (Test 2)", "[XO]")
// {
//   int8_t play[] = {-1, 1, -1, 1, -1, 1};
//   uint8_t pos[] = {4, 0, 3, 7, 6, 8};

//   XO game(play, pos, 6);

//   game.show();

//   REQUIRE(game.makeOptimalMove());

//   game.show();
// }

// TEST_CASE("Guessing instructor tests for makeOptimalMove() for XO (Test 3)", "[XO]")
// {
//   int8_t play[] = {-1, 1, -1, 1, -1, 1, -1, 1, -1};
//   uint8_t pos[] = {0, 2, 1, 3, 4, 6, 5, 7, 8};

//   XO game(play, pos, 9);

//   game.show();

//   REQUIRE_FALSE(game.makeOptimalMove());
//   REQUIRE(game.gameOver());
// }

// TEST_CASE("Testing makeOptimalMove() for XO (Test 4)", "[XO]")
// {
//   int8_t play[] = {-1, 1};
//   uint8_t pos[] = {0, 1};

//   XO game(play, pos, 2);

//   game.show();

//   REQUIRE(game.makeOptimalMove());

//   game.show();

//   //As you can see:
//   /*
//       X O _            X 0 _
//       _ _ _   BECOMES  _ _ _
//       _ _ _            _ _ X
//   */
// }

// TEST_CASE("Testing makeOptimalMove() for XO (Test 5)", "[XO]")
// {
//   int8_t play[] = {-1, 1, -1, 1, -1};
//   uint8_t pos[] = {0, 6, 5, 7, 8};
//   // int8_t play[] = {-1, 1};
//   // uint8_t pos[] = {0, 4};

//   XO game(play, pos, 5);

//   game.show();

//   REQUIRE(game.makeOptimalMove());

//   game.show();

//   REQUIRE(game.makeOptimalMove());

//   game.show();

//   //As you can see:

//   /*
//       X _ _            X 0 _
//       _ _ X  BECOMES   _ _ X
//       0 0 X            0 0 X
//   */

//   /*
//       X 0 _            X 0 _
//       _ _ X  BECOMES   X _ X
//       0 0 X            0 0 X
//   */

//   // REQUIRE(game.makeOptimalMove());
//   // game.show();
//   // REQUIRE(game.makeOptimalMove());
//   // game.show();
//   // REQUIRE(game.makeOptimalMove());
//   // game.show();
//   // REQUIRE(game.makeOptimalMove());
//   // game.show();
//   // REQUIRE(game.makeOptimalMove());
//   // game.show();
//   // REQUIRE(game.makeOptimalMove());
//   // game.show();
// }

// TEST_CASE("Testing makeOptimalMove() for XO (Test 6)", "[XO]")
// {
//   int8_t play[] = {1};
//   uint8_t pos[] = {4};

//   XO game(play, pos, 1);

//   game.show();

//   REQUIRE(game.makeOptimalMove());

//   game.show();

//   REQUIRE(game.makeOptimalMove());
//   game.show();
//   REQUIRE(game.makeOptimalMove());
//   game.show();
//   REQUIRE(game.makeOptimalMove());
//   game.show();
//   REQUIRE(game.makeOptimalMove());
//   game.show();
// }

//GIVEN: STUDENT TEST CASES

// TEST_CASE("Player X immediate win")
// {
//   INFO("Player X eventual win");
//   XO g;
//   g.makeMove(-1, 2);
//   g.makeMove(1, 0);
//   g.makeMove(-1, 3);
//   g.makeMove(1, 7);
//   g.makeMove(-1, 6);
//   g.makeMove(1, 8);

//   g.show();

//   while (!g.gameOver())
//     g.makeOptimalMove();

//   g.show();

//   REQUIRE(g.winner() == -1);
//   REQUIRE(g.getBoard().numMoves == 7);
// }

// TEST_CASE("Optimal block w/certain loss for O")
// {
//   INFO("Optimal block w/certain loss for O");
//   XO g;
//   g.makeMove(-1, 1);
//   g.makeMove(1, 6);
//   g.makeMove(-1, 5);
//   g.makeMove(1, 7);
//   g.makeMove(-1, 8);

//   g.makeOptimalMove();

//   g.show();

//   REQUIRE(g.winner() == 0);
//   REQUIRE(g.getBoard().numMoves == 6);
// }

// TEST_CASE("Player X eventual win")
// {
//   INFO("Player X eventual win");
//   XO g;
//   g.makeMove(-1, 1);
//   g.makeMove(1, 6);
//   g.makeMove(-1, 5);
//   g.makeMove(1, 7);
//   g.makeMove(-1, 8);

//   g.show();

//   while (!g.gameOver())
//     g.makeOptimalMove();

//   g.show();

//   REQUIRE(g.winner() == -1);
//   REQUIRE(g.getBoard().numMoves == 9);
// }

TEST_CASE("Optimal block w/certain loss for X")
{
  INFO("Optimal block w/certain loss for X");
  XO g;
  g.makeMove(1, 1);
  g.makeMove(-1, 6);
  g.makeMove(1, 5);
  g.makeMove(-1, 7);
  g.makeMove(1, 8);

  // while (!g.gameOver())
  //   g.makeOptimalMove();

  g.makeOptimalMove();

  g.show();

  REQUIRE(g.winner() == 0);
  REQUIRE(g.getBoard().numMoves == 6);
}

// TEST_CASE("Player O eventual win")
// {
//   INFO("Player O eventual win");
//   XO g;
//   g.makeMove(1, 1);
//   g.makeMove(-1, 6);
//   g.makeMove(1, 5);
//   g.makeMove(-1, 7);
//   g.makeMove(1, 8);

//   while (!g.gameOver())
//     g.makeOptimalMove();

//   g.show();

//   REQUIRE(g.winner() == 1);
//   REQUIRE(g.getBoard().numMoves == 9);
// }
