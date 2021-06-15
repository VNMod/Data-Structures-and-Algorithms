// Edited by Varun Nimish Modak for Project 1.2,
// Data Structures and Algorithms, Virginia Tech

#ifndef Tape_hpp
#define Tape_hpp

#include "dLinkedList.hpp"
#include <vector>

class Tape
{
public:
    /** Default constructor: creates an empty tape (i.e., no cell).
     @return Sets data fields appropriately. */
    Tape();

    /** Parameterized constructor: creates a tape with symbols from v (one cell per symbol).
     @param v A vector containing symbols.
     @return Sets data fields appropriately. */
    Tape(std::vector<std::string> v);

    /** Copy constructor: performs a deep copy of toCopy. If toCopy is empty, then
     the tape is also empty.
     @param toCopy A tape to copy.
     @return Sets data fields appropriately. */
    Tape(const Tape &toCopy);

    /** Destructor: deallocates memory as appropriate. */
    ~Tape();

    /** Gets the current number of cells in the tape.
     @return The integer number of cells currently in the tape. */
    int getSize() const;

    /** Returns the current tape location, i.e., cell. If the tape is empty, then return -1.
     @return An integer denoting the current cell in the tape.  */
    int getIndex() const;

    /** Sets the symbols on the tape according to toCopy and overwrites existing symbols, if any. If toCopy is empty, then the tape is also reset to having no symbol.
     @param toCopy A tape to copy.
     @return Sets data fields appropriately. */
    void setTape(Tape toCopy);

    /** Sees whether this tape is empty.
     @return True if the tape is empty, or false if not. */
    bool isEmpty() const;

    /** Move the machine head right by one cell if the current cell is not the end of the tape.
     @return True if the tape can be moved to the right (i.e., there is at least one more cell to the right of the tape), or false if not. */
    bool moveRight();

    /** Move the machine head left by one cell if the current location is not the beginning of the tape.
     @return True if the tape can be moved to the left (i.e., there is at least one more cell to the left of the tape), or false if not. */
    bool moveLeft();

    /** Writes a blank symbol (" ") to the current cell in the tape if said cell is valid.
     @return True if the tape can be written at the current cell, or false if not. */
    bool writeBlank();

    /** Writes the symbol specified by s to the current cell in the tape if said cell is valid.
     @param s A symbol.
     @return True if the tape can be written at the current cell, or false if not. */
    bool writeSymbol(std::string s);

    /** Reads the symbol at the current cell in the tape if said cell is valid.
     @return True if the tape can be read at the current cell, or false if not. */
    std::string readSymbol() const;

    /** Clears the tape so that it is now empty.
     @return Sets data fields appropriately. */
    void clear();

    /** Prints the cells on the tape from beginning to end.
     @return Content of tape to standard output.
     NOTE: You do not need to test this method.*/
    void printTape() const;

    /** Rewinds the tape to the very beginning (i.e., first cell) if the tape is not empty.
     @return Sets data fields appropriately. */
    void rewind();

private:
    //You need to determine what the private member variables should be.
    //You may also add private methods if you wish.
    //The only constraints are that:
    //  1. You do not modify the public methods in any way.
    //  2. You do not add additional #include
    //  3. You do not explicitly call the dNode class/methods.
    //The grader will explicitly check for the above requirements and will not
    //give you any points for your implementation if you do not respect
    //these constraints.

    int cellCount;
    int machineheadptr; //keeps track of which cell the machine head pointer is pointing at
    dLinkedList<std::string> TapeCells;
};

#include "Tape.cpp"

#endif /* Tape_hpp */
