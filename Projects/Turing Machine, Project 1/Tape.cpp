//Edited by: Varun Nimish Modak for P1.2 Data Structures and Algorithms
#include "Tape.hpp"

// Default constructor: Creates an empty tape (i.e. no Cell)
Tape::Tape() : cellCount(0), machineheadptr(0), TapeCells()
{
}

// Parameterized constructor: Creates a tape with symbols from a vector v (with one cell per symbol)
Tape::Tape(std::vector<std::string> v)
{
    int i = 0;

    while (i < v.size()) //until all the symbols have been copied
    {
        std::string s = v.operator[](i);
        TapeCells.addBack(s); //keep adding the symbols to each cell of the Tape
        i++;
    }
    machineheadptr = 0;
    cellCount = TapeCells.getCurrentSize();
}

// Copy constructor: performs a deep copy of toCopy. If toCopy is empty, then the tape is also empty.
Tape::Tape(const Tape &toCopy)
{
    int i = 0;
    cellCount = toCopy.getSize();
    machineheadptr = toCopy.getIndex();
    if (!toCopy.isEmpty())                            //if the toCopy Tape is not empty
        while (i < toCopy.TapeCells.getCurrentSize()) // while there are cells left to copy
        {
            //setting the machineheadptr to the first cell on adding symbols
            TapeCells.addBack(toCopy.TapeCells.getItem(i)); //add toCopy's cells into the native Tape's cells
            i++;
        }
    else
    {
        clear();
    }
}

// Destructor: deallocates memory as appropriate.
Tape::~Tape()
{
    cellCount = 0;
    TapeCells.clear();
}

// Method: Gets the current number of cells in the tape
int Tape::getSize() const
{
    return TapeCells.getCurrentSize();
}

// Method: Returns the current tape location, i.e., cell. If the tape is empty, then return -1
int Tape::getIndex() const
{
    if (!isEmpty())
        return machineheadptr;
    else
        return -1;
}

/* Method: Sets the symbols on the tape according to toCopy and overwrites existing symbols, 
if any. If toCopy is empty, then the tape is also reset to having no symbol. */

void Tape::setTape(Tape toCopy)
{
    if (toCopy.isEmpty())
    {
        clear(); //clears the tape if toCopy is empty
    }
    else
    {
        int i = 0;
        clear();
        cellCount = toCopy.getSize();
        machineheadptr = toCopy.getIndex();
        if (!toCopy.isEmpty())                            //if the toCopy Tape is not empty
            while (i < toCopy.TapeCells.getCurrentSize()) // while there are cells left to copy
            {
                TapeCells.addBack(toCopy.TapeCells.getItem(i)); //add toCopy's cells into the native Tape's cells
                i++;
            }
    }
}

// Method: Sees whether this tape is empty
bool Tape::isEmpty() const
{
    return TapeCells.isEmpty();
}

// Method: Moves the machine head right by one cell if the current cell is not the end of the tape.
bool Tape::moveRight()
{
    machineheadptr++;                                //machine head is incremented to the next index
    if (machineheadptr < getSize() && getSize() > 0) //the incremented machine head value is evaluated against the existing size of the Tape
    {
        return true;
    }
    else //if the machinehead is now beyond the end of the tape
    {
        machineheadptr--; //machine head is decremented back to the current index/location
        return false;
    }
}

// Method: Move the machine head left by one cell if the current location is not the beginning of the tape.
bool Tape::moveLeft()
{
    machineheadptr--;                           //machine head is decremented to the previous index
    if ((machineheadptr > -1) && getSize() > 0) //the decremented machine head value is evaluated against the existing size of the Tape
    {
        return true;
    }
    else //if at the beginning of the tape
    {
        machineheadptr++; //machine head is incremented back to the current index/location
        return false;
    }
}

// Method: Writes a blank symbol (" ") to the current cell in the tape if said cell is valid.
bool Tape::writeBlank()
{
    std::string blank = " ";
    if (machineheadptr < getSize() && !isEmpty()) //if the cell exists
    {
        TapeCells.replace(machineheadptr, blank); //replaces " " to the current cell
        return true;
    }
    else
        return false;
}

// Method: Reads the symbol at the current cell in the tape if said cell is valid.
bool Tape::writeSymbol(std::string s)
{
    std::string symbol = s;
    if (machineheadptr < getSize() && !isEmpty()) //if the cell exists and Tape isn't empty
    {
        TapeCells.replace(machineheadptr, symbol); //inserts the symbol and the current cell
        return true;
    }
    else
        return false;
}

// Method: Reads the symbol at the current cell in the tape if said cell is valid.
std::string Tape::readSymbol() const
{
    std::string symbol;
    if (machineheadptr < getSize() && !isEmpty()) //if the cell exists
    {
        symbol = TapeCells.getItem(machineheadptr); //inserts the symbol to the current cell
        return symbol;
    }
    else
        return "";
}

// Method: Clears the tape so that it is now empty
void Tape::clear()
{
    TapeCells.clear();
    machineheadptr = 0;
    cellCount = 0;
}

// Method: Prints the cells on the tape from beginning to end
void Tape::printTape() const
{
    int index = 0;
    std::cout << "The contents of the list are: " << std::endl;
    while (index < getSize())
    {
        std::cout << index << ". " << TapeCells.getItem(index) << std::endl;
        index++;
    }
}

// Method: Rewinds the tape to the very beginning (i.e., first cell) if the tape is not empty
void Tape::rewind()
{
    if (!isEmpty())
        machineheadptr = 0;
}