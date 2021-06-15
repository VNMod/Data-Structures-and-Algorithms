// Edited By Varun Nimish Modak for Project 1.2,
// Data Structures and Algorithms, Virginia Tech

#ifndef TuringMachine_hpp
#define TuringMachine_hpp

#include "Tape.hpp"
#include <vector>

class TuringMachine
{
public:
    /** Default constructor: creates an empty Turing machine.
     @return Sets data fields appropriately. */
    TuringMachine();

    /** Parameterized constructor: creates a Turing machine with tape whose content is identical to toCopy and whose legal symbols are as specified by p.
     @param toCopy A tape to copy content from.
     @param p A vector containing legal symbols.
     @return Sets data fields appropriately. */
    TuringMachine(Tape toCopy, const std::vector<std::string> &p);

    /** Destructor: deallocates memory as appropriate. */
    ~TuringMachine();

    /** Gets the legal symbols that can be written to the tape.
     @return A vector containing all the legal symbols in the Turing machine. */
    std::vector<std::string> getSymbols() const;

    /** Gets the tape from the Turing machine.
     @return The appropriate tape. */
    Tape getTape();

    /** Sets the legal symbols that can be written to the tape, overwriting old symbols if applicable.
     @param p A vector containing legal symbols.
     @return True if the symbols have been set, or false otherwise. */
    bool setSymbols(std::vector<std::string> p);

    /** Sets the tape content to be as specified by toCopy, overwriting old content if applicable.
     @param toCopyA tape to copy content from.
     @return True if the tape have been set, or false otherwise. */
    bool setTape(Tape &toCopy);

    /** This method is specific to the pattern we're checking. For our purpose, this method simply checks that there are exactly 3 legal, no duplicate symbols.
     @return True if the setup is correct, or false otherwise. */
    bool setupCheck();

    /** Resets the Turing machine to empty tape and no symbol list.
     @return Set appropriate data fields. */
    void reset();

    /** Checks to see if content of the tape matches the pattern: a^i b^j c^j, where i and j are integers greater than or equal to 1. Also checks if the tape contains illegal symbols.
     @return True if the pattern matches and there are no illegal symbols, or false otherwise. */
    bool patternMatch();

private:
    Tape t;                           //Tape containing the symbols
    std::vector<std::string> symbols; //Legal symbols that can be written to tape

    //You may add additional private member variables or methods.
    //The only constraints are that:
    //  1. You do not modify the public methods in any way.
    //  2. You do not add additional #include
    //  3. You do not explicitly call the dNode class/methods.
    //The grader will explicitly check for the above requirements and will not
    //give you any points for your implementation if you do not respect
    //these constraints.
};

#include "TuringMachine.cpp"

#endif /* TuringMachine_hpp */
