# turing-machine

### Date: December 2020

## Task:

This program creates a simple database for querying basketball statistics.

## Criteria:

* Reading a csv file containing the relevant basketball statistics
* Building a database from these statistics using STL containers & iterators
* Querying this database, with O(log n) complexity, to find all the games in which players exceed a single, or combination of, user-define statistical value(s).

## Overview, Important Aspects and Limitations:

### CSV file (db.csv):

- The data in this file is structured such that the statistical categories and information appear on the first line of the file, separated by commas.
- The subsequent lines contain the values for the category for each player in a given game.

### BBDB:

Important Note: Once data has been loaded into memory, it cannot be sorted using any sorting algorithm.

#### Player (struct in bbdp.hpp, bbdp.cpp):

- A struct called Player was created that contains an index for identification and a variety of data members for that player's statistics on a given game day. 
- The statistics include the player's full name, first name, last name, game date, points, assists, steals and blocks.

#### Database:

- a std::multiset was used to store a multiset of Player records as a database.
- This was an appropriate choice because like self-balancing binary search trees, mutisets' search, insertion and removal operations have logarithmic complexity.
- The < and > operators were overloaded so that players were automatically compared on insertion and not after having been loaded into memory.

### Querying (SELECT method):

- A SQL-like syntax is used to allow users to perform queries. The *select* command of the BBDB class allows a user to specify which categories are of interest and the minimum value to return a result for.
- For example, *playPTS >= 10 AND playAST >= 10* would return a list of players (in all of their games) who scored 10 or more points and assists.
- The result of a query is returned in the format: gameDate,Category1Name,Category1Data,..CategoryNName,CategoryNData.
- As mentioned earlier, each *Player* on a given game day has an index value. So, four multimap<int, int> members were created within the BBDB class, namely playPTS, playAST, playSTL and playBLK, with keys of points, assists, steals, and blocks values and values of unique indices corresponding to each *Player*.
- In order to query, std::intersections and std::unions (which are log n operations) were carried out on the above-mentioned 4 sets. 

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
  
  
