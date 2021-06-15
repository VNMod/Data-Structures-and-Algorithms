// By Varun Nimish Modak for Project 1.2,
// Data Structures and Algorithms, Virginia Tech

#include "TuringMachine.hpp"

// Default constructor: creates an empty Turing machine.
TuringMachine::TuringMachine() : t()
{
}

// Parameterized constructor: creates a Turing machine with tape whose content is identical to toCopy and whose legal symbols are as specified by p.
TuringMachine::TuringMachine(Tape toCopy, const std::vector<std::string> &p)
{
    t.setTape(toCopy);
    setSymbols(p);
}

// Destructor: deallocates memory as appropriate.
TuringMachine::~TuringMachine()
{
    reset();
}

// Method: Gets the legal symbols that can be written to the tape
std::vector<std::string> TuringMachine::getSymbols() const
{
    return symbols;
}

// Method: Gets the tape from the Turing machine
Tape TuringMachine::getTape()
{
    return t;
}

// Method: Sets the legal symbols that can be written to the tape, overwriting old symbols if applicable.
bool TuringMachine::setSymbols(std::vector<std::string> p)
{
    symbols = p;
    return true;
}

// Method: Sets the tape content to be as specified by toCopy, overwriting old content if applicable.
bool TuringMachine::setTape(Tape &toCopy)
{
    t.setTape(toCopy);
    return true;
}

// Method: This method is specific to the pattern we're checking. For our purpose, this method simply
//checks that there are exactly 3 legal, no duplicate symbols.
bool TuringMachine::setupCheck()
{
    if (symbols.size() == 3)
    {
        if (symbols[0] == symbols[1] || symbols[1] == symbols[2] || symbols[0] == symbols[2])
        {
            // if (symbols[0] == "a" || symbols[1] == "a" || symbols[2] == "a")
            //     if (symbols[0] == "b" || symbols[1] == "b" || symbols[2] == "b")
            //         if (symbols[0] == "c" || symbols[1] == "c" || symbols[2] == "c")
            return false;
        }
        else
            return true;
    }
    else
        return false;
}

// Method: Resets the Turing machine to empty tape and no symbol list.
void TuringMachine::reset()
{
    t.clear();
    int i = 0;
    int size = symbols.size();
    while (i < size)
    {
        symbols.pop_back();
        i++;
    }
}

// Method: checks to see if content of the tape matches the pattern: a^i b^j c^j, where i and j are integers
// greater than or equal to 1. Also checks if the tape contains illegal symbols.
bool TuringMachine::patternMatch()
{
    if (t.readSymbol() == "a")
    {
        t.moveRight(); //first symbol must be "a"
        while (t.readSymbol() == "a" && t.getIndex() < (t.getSize() - 1))
        {
            t.moveRight(); //till all the "a" symbols have been traversed across
        }
        if (t.readSymbol() == "b")
        {
            t.writeSymbol("X"); //writing the "X" at the first cell containing "b"
            t.moveRight();
            if (t.readSymbol() == "b" || t.readSymbol() == "c") //next cell must either contain a "b" or "c"
            {
                while ((t.readSymbol() == "b" || t.readSymbol() == "c") && t.getIndex() < (t.getSize() - 1)) //move right till you reach the end of the Tape
                {
                    t.moveRight();
                    if (t.readSymbol() != "b" && t.readSymbol() != "c") //if any illegal characters exist, return false
                        return false;
                }
                if (t.readSymbol() == "c") //writing y at the last cell
                {
                    t.writeSymbol("Y");
                }
                else // if the last cell does not contain a "c"
                    return false;

                while (true)
                {
                    while (t.readSymbol() != "X") //move left till you reach the cell containing "X"
                    {
                        t.moveLeft();
                    }
                    t.moveRight();                                      //move right from the cell containing "X"
                    if (t.readSymbol() != "b" && t.readSymbol() != "c") // in case of a^i, b^j, c^j
                    {
                        return true;
                    }
                    else if (t.readSymbol() == "b")
                    {
                        t.writeSymbol("X");
                        while (t.readSymbol() != "Y") //till you encounter the first cell containing "Y"
                        {
                            t.moveRight();
                        }
                        t.moveLeft(); //move left from the cell containing "Y"
                        if (t.readSymbol() == "c")
                        {
                            t.writeSymbol("Y");
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else if (t.readSymbol() == "c") // in case of a^i, b^j, c^k where j is not equal to k
                    {
                        return false;
                    }
                }
            }
            else // if the symbol after the first "b" is not a "b" or "c"
            {
                return false;
            }
        }
        else //if the symbol "b" does not follow after the cells containing "a" have been passed by
        {
            return false;
        }
    }
    else //if the first symbol is not "a" then it's false
    {
        return false;
    }
}