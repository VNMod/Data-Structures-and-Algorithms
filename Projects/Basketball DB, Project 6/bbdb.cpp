// Project 6 - Final Exam for Data Structures and Algorithms ECE2574

#include "bbdb.hpp"
#include <fstream>
#include <algorithm>

// Default Constructor: read file db.csv in current directory and build indices for searching
//                      throws std::runtime_error if db.csv cannot be read

BBDB::BBDB()
{
    //ifstream object (for reading from a .csv file)
    std::ifstream in("db.csv", std::ios::in);

    if (!in)
    {
        throw std::logic_error("The .csv file cannot be read! Check the name or directory");
    }

    std::string line, word;

    std::getline(in, line); //obtain the first line
    std::stringstream str(line);

    int j = 0;

    // Indices for each category (first row of the .csv file):
    int gmDateIDX, playLNMIDX, playFNMIDX, playDispNmIDX, playASTIDX, playPTSIDX, playSTLIDX, playBLKIDX;

    // assigning indices for each category
    while (std::getline(str, word, ','))
    {
        if (word == "gmDate")
        {
            gmDateIDX = j;
        }
        else if (word == "playLNm")
        {
            playLNMIDX = j;
        }
        else if (word == "playFNm")
        {
            playFNMIDX = j;
        }
        else if (word == "playDispNm")
        {
            playDispNmIDX = j;
        }
        else if (word == "playPTS")
        {
            playPTSIDX = j;
        }
        else if (word == "playAST")
        {
            playASTIDX = j;
        }
        else if (word == "playSTL")
        {
            playSTLIDX = j;
        }
        else if (word == "playBLK")
        {
            playBLKIDX = j;
        }

        j++;
    }

    int index = 0;

    // while reading each consecutive row of the .csv file
    while (std::getline(in, line))
    {
        std::vector<std::string> row;
        std::stringstream s(line);
        //breaking the line into multiple words and adding them to the row vector
        while (std::getline(s, word, ','))
        {
            row.push_back(word);
        }

        Player p;

        // assigning the player's fields their values
        p.fullName = row[playFNMIDX] + " " + row[playLNMIDX];
        p.playLastName = row[playLNMIDX];
        p.playFirstName = row[playFNMIDX];
        p.gameDate = row[gmDateIDX];
        p.playAST = std::stoi(row[playASTIDX]);
        p.playPTS = std::stoi(row[playPTSIDX]);
        p.playBLK = std::stoi(row[playBLKIDX]);
        p.playSTL = std::stoi(row[playSTLIDX]);
        p.index = index;

        playPTS.insert({p.playPTS, index});
        playAST.insert({p.playAST, index});
        playSTL.insert({p.playSTL, index});
        playBLK.insert({p.playBLK, index});

        //inserting the record for each player profile with a unique index as its key
        players.insert(p);

        index++;
    }

    // PrintAllRecords(); //for testing if all the records were being printed
}

// Parameterized Constructor: Use the parameter to read the given csv file and build indices for searching
//                            @param filename - name (with path) to csv file containing database information
//                            throws std::runtime_error if file cannot be read

BBDB::BBDB(std::string filename)
{
    //ifstream object (for reading from a .csv file)
    std::ifstream in(filename, std::ios::in);

    if (!in)
    {
        throw std::logic_error("The .csv file cannot be read! Check the name or directory");
    }

    std::string line, word;

    std::getline(in, line); //obtain the first line
    std::stringstream str(line);

    int j = 0;

    // Indices for each category (first row of the .csv file):
    int gmDateIDX, playLNMIDX, playFNMIDX, playDispNmIDX, playASTIDX, playPTSIDX, playSTLIDX, playBLKIDX;

    // assigning indices for each category
    while (std::getline(str, word, ','))
    {
        if (word == "gmDate")
        {
            gmDateIDX = j;
        }
        else if (word == "playLNm")
        {
            playLNMIDX = j;
        }
        else if (word == "playFNm")
        {
            playFNMIDX = j;
        }
        else if (word == "playDispNm")
        {
            playDispNmIDX = j;
        }
        else if (word == "playPTS")
        {
            playPTSIDX = j;
        }
        else if (word == "playAST")
        {
            playASTIDX = j;
        }
        else if (word == "playSTL")
        {
            playSTLIDX = j;
        }
        else if (word == "playBLK")
        {
            playBLKIDX = j;
        }

        j++;
    }

    int index = 0;

    // while reading each consecutive row of the .csv file
    while (std::getline(in, line))
    {
        std::vector<std::string> row;
        std::stringstream s(line);
        //breaking the line into multiple words and adding them to the row vector
        while (std::getline(s, word, ','))
        {
            row.push_back(word);
        }

        Player p;

        // assigning the player's fields their values
        p.fullName = row[playFNMIDX] + " " + row[playLNMIDX];
        p.playLastName = row[playLNMIDX];
        p.playFirstName = row[playFNMIDX];
        p.gameDate = row[gmDateIDX];
        p.playAST = std::stoi(row[playASTIDX]);
        p.playPTS = std::stoi(row[playPTSIDX]);
        p.playBLK = std::stoi(row[playBLKIDX]);
        p.playSTL = std::stoi(row[playSTLIDX]);
        p.index = index;

        playPTS.insert({p.playPTS, index});
        playAST.insert({p.playAST, index});
        playSTL.insert({p.playSTL, index});
        playBLK.insert({p.playBLK, index});

        //inserting the record for each player profile with a unique index as its key
        players.insert(p);

        index++;
    }

    // PrintAllRecords(); //for testing if all the records were being printed
}

// Method: Search over all entries in database to find games in which a player meets or exceeds values in statistical categories provided by user
std::vector<std::string> BBDB::select(std::string query) const
{
    std::stringstream str(query); //treats the given query string as a stream

    std::vector<std::string> query_words; //contain each word of the given query

    std::string word;

    // store each of the provided query in a vector
    while (std::getline(str, word, ' '))
    {
        query_words.push_back(word);
    }

    //now, query_words contains all the words of the given query

    std::vector<std::string> single_queries; //list of single queries
    std::vector<std::string> categories;     //list of categories being queried

    std::string temp = "";

    for (int i = 0; i <= query_words.size(); i++)
    {
        if (query_words[i + 1] == ">=")
        {
            categories.push_back(query_words[i]);
        }

        if (query_words[i] == "AND" || i == query_words.size())
        {
            single_queries.push_back(temp);
            temp = "";
            continue; //don't append a single query with AND
        }

        temp = temp + query_words[i] + " ";
    }

    int pts_thres = -1;
    int ast_thres = -1;
    int stl_thres = -1;
    int blk_thres = -1;

    bool pts_thres_exists = false;
    bool ast_thres_exists = false;
    bool stl_thres_exists = false;
    bool blk_thres_exists = false;

    // //Now, that we stored each single query we can make sense of each comparison and category

    for (int i = 0; i < single_queries.size(); i++)
    {
        std::stringstream st(single_queries[i]); //treats the given query string as a stream

        int pos = 0;

        std::string category;
        while (std::getline(st, word, ' '))
        {
            if (word == "playPTS")
            {
                category = "playPTS";
            }
            else if (word == "playAST")
            {
                category = "playAST";
            }
            else if (word == "playSTL")
            {
                category = "playSTL";
            }
            else if (word == "playBLK")
            {
                category = "playBLK";
            }

            if (pos == 2)
            {
                std::multiset<int>::iterator x;
                if (category == "playPTS")
                {
                    pts_thres = std::stoi(word);
                    pts_thres_exists = true;
                }
                else if (category == "playAST")
                {
                    ast_thres = std::stoi(word);
                    ast_thres_exists = true;
                }
                else if (category == "playSTL")
                {
                    stl_thres = std::stoi(word);
                    stl_thres_exists = true;
                }
                else if (category == "playBLK")
                {
                    blk_thres = std::stoi(word);
                    blk_thres_exists = true;
                }
            }
            pos++;
        }
    }

    std::multiset<int> indices_pts_thres;
    std::multiset<int> indices_ast_thres;
    std::multiset<int> indices_stl_thres;
    std::multiset<int> indices_blk_thres;

    std::multiset<int> union1;
    std::multiset<int> union2;
    std::multiset<int> union3;
    std::multiset<int> union4;
    std::multiset<int> intersection2;
    std::multiset<int> intersection3;
    std::multiset<int> intersection4;

    std::multiset<int> empty_set;
    std::vector<int> index;

    // Performs either unions or intersections, to obtain the set with the final queried data

    if (pts_thres_exists) //if there exists a threshold for playPTS, remove those below the threshold
    {
        std::multiset<int>::iterator it;
        auto itlb = playPTS.lower_bound(pts_thres);
        for (auto &it = itlb; it != playPTS.end(); ++it)
        {
            indices_pts_thres.insert(it->second);
        }

        std::set_union(indices_pts_thres.begin(), indices_pts_thres.end(), empty_set.begin(), empty_set.end(), std::inserter(union1, union1.end()));
    }
    if (ast_thres_exists) //if there exists a threshold for playAST, remove the indices of those below the threshold
    {
        std::multiset<int>::iterator it;
        auto itlb = playAST.lower_bound(ast_thres);
        for (auto &it = itlb; it != playAST.end(); ++it)
        {
            indices_ast_thres.insert(it->second);
        }

        if (!pts_thres_exists)
        {
            std::set_union(indices_ast_thres.begin(), indices_ast_thres.end(), empty_set.begin(), empty_set.end(), std::inserter(union2, union2.end()));
        }
        else
        {
            std::set_intersection(indices_ast_thres.begin(), indices_ast_thres.end(), union1.begin(), union1.end(), std::inserter(intersection2, intersection2.end()));
        }
    }
    if (stl_thres_exists) //if there exists a threshold for playSTL, remove the indices of  those below the threshold
    {
        std::multiset<int>::iterator it;
        auto itlb = playSTL.lower_bound(stl_thres);
        for (auto &it = itlb; it != playSTL.end(); ++it)
        {
            indices_stl_thres.insert(it->second);
        }

        if (!pts_thres_exists && !ast_thres_exists)
        {
            std::set_union(indices_stl_thres.begin(), indices_stl_thres.end(), empty_set.begin(), empty_set.end(), std::inserter(union3, union3.end()));
        }
        else if (pts_thres_exists && ast_thres_exists)
        {
            std::set_intersection(indices_stl_thres.begin(), indices_stl_thres.end(), intersection2.begin(), intersection2.end(), std::inserter(intersection3, intersection3.end()));
        }
        else if (pts_thres_exists && !ast_thres_exists)
        {
            std::set_intersection(indices_stl_thres.begin(), indices_stl_thres.end(), union1.begin(), union1.end(), std::inserter(intersection3, intersection3.end()));
        }
        else if (!pts_thres_exists && ast_thres_exists)
        {
            std::set_intersection(indices_stl_thres.begin(), indices_stl_thres.end(), union2.begin(), union2.end(), std::inserter(intersection3, intersection3.end()));
        }
    }
    if (blk_thres_exists) //if there exists a threshold for playBLK, remove the indices of  those below the threshold
    {
        std::multiset<int>::iterator it;
        auto itlb = playBLK.lower_bound(blk_thres);
        for (auto &it = itlb; it != playBLK.end(); ++it)
        {
            indices_blk_thres.insert(it->second);
        }

        if (!pts_thres_exists && !ast_thres_exists && !stl_thres_exists)
        {
            std::set_union(indices_blk_thres.begin(), indices_blk_thres.end(), empty_set.begin(), empty_set.end(), std::inserter(union4, union4.end()));
        }
        else if (pts_thres_exists && ast_thres_exists && stl_thres_exists)
        {
            std::set_intersection(indices_blk_thres.begin(), indices_blk_thres.end(), intersection3.begin(), intersection3.end(), std::inserter(intersection4, intersection4.end()));
        }
        else if (pts_thres_exists && !ast_thres_exists && !stl_thres_exists)
        {
            std::set_intersection(indices_blk_thres.begin(), indices_blk_thres.end(), union1.begin(), union1.end(), std::inserter(intersection4, intersection4.end()));
        }
        else if (!pts_thres_exists && ast_thres_exists && !stl_thres_exists)
        {
            std::set_intersection(indices_blk_thres.begin(), indices_blk_thres.end(), union2.begin(), union2.end(), std::inserter(intersection4, intersection4.end()));
        }
        else if (!pts_thres_exists && !ast_thres_exists && stl_thres_exists)
        {
            std::set_intersection(indices_blk_thres.begin(), indices_blk_thres.end(), union3.begin(), union3.end(), std::inserter(intersection4, intersection4.end()));
        }
        else if (pts_thres_exists && ast_thres_exists && !stl_thres_exists)
        {
            std::set_intersection(indices_blk_thres.begin(), indices_blk_thres.end(), intersection2.begin(), intersection2.end(), std::inserter(intersection4, intersection4.end()));
        }
        else if (pts_thres_exists && !ast_thres_exists && stl_thres_exists)
        {
            std::set_intersection(indices_blk_thres.begin(), indices_blk_thres.end(), intersection3.begin(), intersection3.end(), std::inserter(intersection4, intersection4.end()));
        }
        else if (!pts_thres_exists && ast_thres_exists && stl_thres_exists)
        {
            std::set_intersection(indices_blk_thres.begin(), indices_blk_thres.end(), intersection3.begin(), intersection3.end(), std::inserter(intersection4, intersection4.end()));
        }
    }

    //now, for an existing set of indices, the values are copied over to a vector of index values in integer
    // 15 cases in total:
    if (pts_thres_exists && !ast_thres_exists && !stl_thres_exists && !blk_thres_exists)
    {
        std::multiset<int>::iterator iter;
        for (iter = union1.begin(); iter != union1.end(); iter++)
        {
            index.push_back(*iter);
        }
    }
    else if (!pts_thres_exists && ast_thres_exists && !stl_thres_exists && !blk_thres_exists)
    {
        std::multiset<int>::iterator iter;
        for (iter = union2.begin(); iter != union2.end(); iter++)
        {
            index.push_back(*iter);
        }
    }
    else if (!pts_thres_exists && !ast_thres_exists && stl_thres_exists && !blk_thres_exists)
    {
        std::multiset<int>::iterator iter;
        for (iter = union3.begin(); iter != union3.end(); iter++)
        {
            index.push_back(*iter);
        }
    }
    else if (!pts_thres_exists && !ast_thres_exists && !stl_thres_exists && blk_thres_exists)
    {
        std::multiset<int>::iterator iter;
        for (iter = union4.begin(); iter != union4.end(); iter++)
        {
            index.push_back(*iter);
        }
    }
    else if (pts_thres_exists && ast_thres_exists && !stl_thres_exists && !blk_thres_exists)
    {
        std::multiset<int>::iterator iter;
        for (iter = intersection2.begin(); iter != intersection2.end(); iter++)
        {
            index.push_back(*iter);
        }
    }
    else if (pts_thres_exists && !ast_thres_exists && stl_thres_exists && !blk_thres_exists)
    {
        std::multiset<int>::iterator iter;
        for (iter = intersection3.begin(); iter != intersection3.end(); iter++)
        {
            index.push_back(*iter);
        }
    }
    else if (pts_thres_exists && !ast_thres_exists && !stl_thres_exists && blk_thres_exists)
    {
        std::multiset<int>::iterator iter;
        for (iter = intersection4.begin(); iter != intersection4.end(); iter++)
        {
            index.push_back(*iter);
        }
    }
    else if (pts_thres_exists && ast_thres_exists && stl_thres_exists && !blk_thres_exists)
    {
        std::multiset<int>::iterator iter;
        for (iter = intersection3.begin(); iter != intersection3.end(); iter++)
        {
            index.push_back(*iter);
        }
    }
    else if (pts_thres_exists && !ast_thres_exists && stl_thres_exists && blk_thres_exists)
    {
        std::multiset<int>::iterator iter;
        for (iter = intersection4.begin(); iter != intersection4.end(); iter++)
        {
            index.push_back(*iter);
        }
    }
    else if (pts_thres_exists && ast_thres_exists && !stl_thres_exists && blk_thres_exists)
    {
        std::multiset<int>::iterator iter;
        for (iter = intersection4.begin(); iter != intersection4.end(); iter++)
        {
            index.push_back(*iter);
        }
    }
    else if (!pts_thres_exists && ast_thres_exists && stl_thres_exists && blk_thres_exists)
    {
        std::multiset<int>::iterator iter;
        for (iter = intersection4.begin(); iter != intersection4.end(); iter++)
        {
            index.push_back(*iter);
        }
    }
    else if (!pts_thres_exists && ast_thres_exists && stl_thres_exists && !blk_thres_exists)
    {
        std::multiset<int>::iterator iter;
        for (iter = intersection3.begin(); iter != intersection3.end(); iter++)
        {
            index.push_back(*iter);
        }
    }
    else if (!pts_thres_exists && ast_thres_exists && !stl_thres_exists && blk_thres_exists)
    {
        std::multiset<int>::iterator iter;
        for (iter = intersection4.begin(); iter != intersection4.end(); iter++)
        {
            index.push_back(*iter);
        }
    }
    else if (!pts_thres_exists && !ast_thres_exists && stl_thres_exists && blk_thres_exists)
    {
        std::multiset<int>::iterator iter;
        for (iter = intersection4.begin(); iter != intersection4.end(); iter++)
        {
            index.push_back(*iter);
        }
    }
    else if (pts_thres_exists && ast_thres_exists && stl_thres_exists && blk_thres_exists)
    {
        std::multiset<int>::iterator iter;
        for (iter = intersection4.begin(); iter != intersection4.end(); iter++)
        {
            index.push_back(*iter);
        }
    }

    //now, we should have the indices of all the players whose records need to be displayed:
    //let's store this in a vector

    std::sort(index.begin(), index.end()); // sort the given set of indices

    std::multiset<Player, std::less<Player>>::iterator x;

    std::vector<std::string> queried_players;

    int i = 0;
    for (x = players.begin(); x != players.end(); x++)
    {
        if (i == index.size() || index.size() == 0)
        {
            break;
        }
        if (x->index == index[i])
        {
            i++;
            std::string result;
            result = x->gameDate + "," + x->fullName;

            if (pts_thres_exists)
            {
                std::stringstream ss;
                ss << x->playPTS;
                std::string PTS = ss.str();
                result = result + ",playPTS," + PTS;
            }
            if (ast_thres_exists)
            {
                std::stringstream ss;
                ss << x->playAST;
                std::string AST = ss.str();
                result = result + ",playAST," + AST;
            }
            if (stl_thres_exists)
            {
                std::stringstream ss;
                ss << x->playSTL;
                std::string STL = ss.str();
                result = result + ",playSTL," + STL;
            }
            if (blk_thres_exists)
            {
                std::stringstream ss;
                ss << x->playBLK;
                std::string BLK = ss.str();
                result = result + ",playBLK," + BLK;
            }

            queried_players.push_back(result);
        }
    }

    //printing the queried items
    // for (int i = 0; i < queried_players.size(); i++)
    // {
    //     std::cout << queried_players[i] << std::endl;
    // }

    return queried_players;
}

// Method: to print all the records as stored in the database (on extraction from the associated .csv file)
void BBDB::PrintAllRecords()
{
    std::multiset<Player>::const_iterator itr;

    for (itr = players.begin(); itr != players.end(); itr++)
    {
        std::cout << itr->gameDate << "," << itr->fullName << "," << itr->playPTS << "," << itr->playBLK << std::endl;
    }
}