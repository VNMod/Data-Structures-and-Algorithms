// Project 6 - Final Exam for Data Structures and Algorithms ECE2574

#ifndef BBDB_HPP
#define BBDB_HPP

#include <string>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <iostream>
#include <iterator>

class BBDB
{
public:
  /** 
   * Default constructor: read file db.csv in current directory and build indices for searching
   * throws std::runtime_error if db.csv cannot be read
   */
  BBDB();

  /**
   * Use the parameter to read the given csv file and build indices for searching
   * @param filename - name (with path) to csv file containing database information
   * throws std::runtime_error if file cannot be read
   */
  BBDB(std::string filename);

  /**
   * Search over all entries in database to find games in which a player meets or exceeds values in statistical categories provided by user
   * throws std::runtime_error if query is invalid
   * @param query - database search string consisting of statistical category and respective minimum value player must exceed
   * @return empty std::vector if there are no results that match query or vector of strings consisting of `gmDate,playDispNm,Category1Name,Category1Data,...,CategoryNName,CategoryNData' for each player in each game matching search criteria
   */
  std::vector<std::string> select(std::string query) const;

private:
  // Method to print all the stored records
  void PrintAllRecords();

  // Profile of an entire player (including the stats for his performance on that particular night)
  struct Player
  {
  public:
    int index;
    std::string fullName;
    std::string playLastName;
    std::string playFirstName;
    std::string gameDate;

    // Stats for the player during a particular game
    int playPTS; // Points
    int playAST; // Assists
    int playSTL; // Steals
    int playBLK; // Blocks

    // these are the threshold values that are set by a passed query
    int PTS_thres = 0;
    int AST_thres = 0;
    int STL_thres = 0;
    int BLK_thres = 0;

    // operator overload: assists in sorting as per constraints on consecutive inserts
    // this method is used by the std::less<> specialization that multisets are set to by default
    bool operator<(const Player &rhs) const
    {
      bool comparison; // truth value for <

      std::stringstream str1(gameDate);
      std::stringstream str2(rhs.gameDate);

      int day1, month1, year1;
      int day2, month2, year2;

      std::vector<std::string> dates1;
      std::vector<std::string> dates2;

      std::string word;

      while (std::getline(str1, word, '-'))
      {
        dates1.push_back(word);
      }

      while (std::getline(str2, word, '-'))
      {
        dates2.push_back(word);
      }

      // date of game for this player
      month1 = std::stoi(dates1[0]);
      day1 = std::stoi(dates1[1]);
      year1 = std::stoi(dates1[2]);

      // date of game for other player -- rhs
      month2 = std::stoi(dates2[0]);
      day2 = std::stoi(dates2[1]);
      year2 = std::stoi(dates2[2]);

      int less = 0;

      // now, we must compare the dates

      if (year1 < year2)
      {
        less = 1;
      }
      else if (year2 < year1)
      {
        less = 2;
      }
      else
      {
        if (month1 < month2)
        {
          less = 1;
        }
        else if (month2 < month1)
        {
          less = 2;
        }
        else
        {
          if (day1 < day2)
          {
            less = 1;
          }
          else if (day2 < day1)
          {
            less = 2;
          }
          else
          {
            less = 0;
          }
        }
      }

      if (less == 1) //as the game Date for this object is lesser than that of the passed rhs object
      {
        comparison = true;
      }
      else if (less == 2) //as the game Date for the rhs object is lesser than that of this object
      {
        comparison = false;
      }
      else //when less == 0 -- i.e. their dates are the same
      {
        std::string lastName1 = playLastName;
        std::string lastName2 = rhs.playLastName;

        if (lastName1.compare(lastName2) < 0)
        {
          comparison = true;
        }
        else
        {
          comparison = false;
        }
      }

      return comparison;
    }

    bool operator>(const Player &rhs) const
    {
      bool comparison; // truth value for <

      std::stringstream str1(gameDate);
      std::stringstream str2(rhs.gameDate);

      int day1, month1, year1;
      int day2, month2, year2;

      std::vector<std::string> dates1;
      std::vector<std::string> dates2;

      std::string word;

      // Note: the delimiter has been set as - instead of /
      // as the compiler interprets the / as - for the date
      // Ex: 2018-03-31 is actually 2018/03/31
      while (std::getline(str1, word, '-'))
      {
        dates1.push_back(word);
      }

      while (std::getline(str2, word, '-'))
      {
        dates2.push_back(word);
      }

      // date of game for this player
      month1 = std::stoi(dates1[0]);
      day1 = std::stoi(dates1[1]);
      year1 = std::stoi(dates1[2]);

      // date of game for other player -- rhs
      month2 = std::stoi(dates2[0]);
      day2 = std::stoi(dates2[1]);
      year2 = std::stoi(dates2[2]);

      int greater = 0;

      // now, we must compare the dates

      if (year1 > year2)
      {
        greater = 1;
      }
      else if (year2 > year1)
      {
        greater = 2;
      }
      else
      {
        if (month1 > month2)
        {
          greater = 1;
        }
        else if (month2 > month1)
        {
          greater = 2;
        }
        else
        {
          if (day1 < day2)
          {
            greater = 1;
          }
          else if (day2 < day1)
          {
            greater = 2;
          }
          else
          {
            greater = 0;
          }
        }
      }

      if (greater == 1) //as the game Date for this object is lesser than that of the passed rhs object
      {
        comparison = true;
      }
      else if (greater == 2) //as the game Date for the rhs object is lesser than that of this object
      {
        comparison = false;
      }
      else //when less == 0 -- i.e. their dates are the same
      {
        std::string lastName1 = playLastName;
        std::string lastName2 = rhs.playLastName;

        if (lastName1.compare(lastName2) > 0)
        {
          comparison = true;
        }
        else
        {
          comparison = false;
        }
      }

      return comparison;
    }
  };

  // <key, value>
  std::multimap<int, int> playPTS; // Points
  std::multimap<int, int> playAST; // Assists
  std::multimap<int, int> playSTL; // Steals
  std::multimap<int, int> playBLK; // Blocks

  // maps provide a functionality similar to that of any self-balancing binary search trees
  // the bool operator overloading method above defines the sorting order based on:
  // date associated with that player's game and alphabetical order of last name (for same dates)
  std::multiset<Player, std::less<Player>> players;
};

#endif
