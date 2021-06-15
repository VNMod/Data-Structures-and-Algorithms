#include <string>

#include "catch.hpp"
#include "bbdb.hpp"

std::string path("../"); //uncomment for submitting to grader
                         // std::string path(".\"); //comment when submitting to grader (Windows)
                         // std::string path("./"); //comment when submitting to grader (Mac/UNIX)

// // Tests the parametrized constructor
// TEST_CASE("Parameterized constructor", "[bbdb]")
// {
//   BBDB db(path + "2017-18_playerBoxScore.csv");
// }

// Tests the default constructor -- playPTS and playAST category (TEST 1)
// TEST_CASE("Default constructor", "[bbdb]")
// {
//   BBDB db;

//   std::vector<std::string> required_result;

//   std::vector<std::string> result;
//   result = db.select("playPTS >= 50 AND playAST >= 10");
// }

// // Tests the parameterized constructor for the same case (TEST 2)
// TEST_CASE("Default constructor -- querying playPTS and playAST categories", "[bbdb]")
// {
//   std::string filename = "db.csv";
//   BBDB db(filename);

//   std::vector<std::string> required_result;

//   std::vector<std::string> result;
//   result = db.select("playPTS >= 50 AND playAST >= 10");

//   //if you print result, you should get:
//   /*
//   2017-11-05,James Harden,playPTS,56,playAST,13
//   2018-01-30,James Harden,playPTS,60,playAST,11
//   */

//   for (int i = 0; i < result.size(); i++)
//   {
//     std::cout << result[i] << std::endl;
//   }
// }

// // Tests the default constructor -- playPTS, playAST and playBLK category (TEST 3)
// TEST_CASE("Default constructor -- querying playPTS, playAST and playBLK categories", "[bbdb]")
// {
//   BBDB db;

//   std::vector<std::string> required_result;

//   std::vector<std::string> result;
//   result = db.select("playPTS >= 33 AND playAST >= 12 AND playSTL >= 2");

//   //if you print result, you should get: 2017-10-24,LeBron James,playPTS,34,playAST,13,playSTL,3

//   for (int i = 0; i < result.size(); i++)
//   {
//     std::cout << result[i] << std::endl;
//   }
// }

// // Tests the default constructor -- playPTS, playAST, playBLK and playSTL category (TEST 4)
// TEST_CASE("Default constructor -- querying playPTS, playAST, playBLK, playSTL categories", "[bbdb]")
// {
//   BBDB db;

//   std::vector<std::string> required_result;

//   std::vector<std::string> result;
//   result = db.select("playPTS >= 11 AND playAST >= 4 AND playSTL >= 1 AND playBLK >= 1");

//   //if you print result, you should get: 2017-10-18,Caris LeVert,playPTS,12,playAST,4,playSTL,2,playBLK,1

//   for (int i = 0; i < result.size(); i++)
//   {
//     std::cout << result[i] << std::endl;
//   }
// }

// // Tests the default constructor -- playPTS, playAST, playBLK and playSTL category (TEST 5)
// TEST_CASE("Default constructor -- querying playPTS, playAST and playSTL categories", "[bbdb]")
// {
//   BBDB db;

//   std::vector<std::string> required_result;

//   std::vector<std::string> result;
//   result = db.select("playPTS >= 22 AND playAST >= 10 AND playSTL >= 3");

//   //if you print result, you should get:
//   /*
//   2017-10-17,Kyrie Irving,playPTS,22,playAST,10,playSTL,3
//   2017-10-24,LeBron James,playPTS,34,playAST,13,playSTL,3
//   2017-10-25,Russell Westbrook,playPTS,28,playAST,16,playSTL,3
//   2017-10-28,DeMarcus Cousins,playPTS,29,playAST,10,playSTL,3
//   2017-10-30,Jeff Teague,playPTS,23,playAST,11,playSTL,6
//   */

//   for (int i = 0; i < result.size(); i++)
//   {
//     std::cout << result[i] << std::endl;
//   }
// }

// // // Tests the default constructor -- playPTS category (TEST 7)
// TEST_CASE("Default constructor -- querying playPTS categories", "[bbdb]")
// {
//   BBDB db;

//   std::vector<std::string> required_result;

//   std::vector<std::string> result;
//   result = db.select("playPTS >= 60");

//   //if you print result, you should get:
//   /*
//   2018-01-30,James Harden,playPTS,60
//   */

//   for (int i = 0; i < result.size(); i++)
//   {
//     std::cout << result[i] << std::endl;
//   }
// }

// // // Tests the default constructor -- playAST category (TEST 8)
TEST_CASE("Default constructor -- querying playAST categories", "[bbdb]")
{
  BBDB db;

  std::vector<std::string> required_result;

  std::vector<std::string> result;
  result = db.select("playAST >= 10");

  //if you print result, you should get:
  /*
      2017-10-17,Kyrie Irving,playAST,10
  */

  for (int i = 0; i < result.size(); i++)
  {
    std::cout << result[i] << std::endl;
  }
}
