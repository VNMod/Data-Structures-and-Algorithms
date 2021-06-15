#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_COLOUR_NONE

#include "catch.hpp"
#include "TuringMachine.hpp"
#include "Tape.hpp"

// I. TESTING THE TAPE CLASS constructors and methods here:

// 1. Testing the default constructor for the Tape Class -- TO TEST TapeCells() STILL
TEST_CASE("Test default constructor for the Tape Class", "[Tape]")
{
    Tape newtape;
    REQUIRE(newtape.getSize() == 0);
    REQUIRE(newtape.getIndex() == -1); //-1 is returned if empty
}

// 2. Testing the parameterized constructor
TEST_CASE("Test parameterized constructor for the Tape Class", "[Tape]")
{
    std::vector<std::string> s = {"A", "a", "B"};
    Tape toCopyCells(s);
    toCopyCells.printTape();
}

// 3. Testing the copy constructor
TEST_CASE("Test copy constructor for the Tape Class", "[Tape]")
{
    // Testing to copy an empty Tape
    Tape toCopyEmpty;
    Tape newtape1(toCopyEmpty);
    REQUIRE(newtape1.isEmpty());

    //Testing to copy a tape with cells
    std::vector<std::string> s{"a", "b", "c", "1"};
    Tape toCopyCells(s);
    toCopyCells.printTape(); //manually checking console to see if the values were copied

    // Testing to "deep copy" another Tape with cells
    Tape newtape2(toCopyCells);

    // Testing to check that the sizes of the tapes are now identical
    REQUIRE(newtape2.getSize() == toCopyCells.getSize());

    // Testing to see if the symbols of toCopyCells have appropriately been copied
    REQUIRE(newtape2.getIndex() == 0);
    REQUIRE(newtape2.readSymbol() == "a");

    newtape2.moveRight();
    REQUIRE(newtape2.getIndex() == 1);
    REQUIRE(newtape2.readSymbol() == "b");

    newtape2.moveRight();
    REQUIRE(newtape2.getIndex() == 2);
    REQUIRE(newtape2.readSymbol() == "c");

    newtape2.moveRight();
    REQUIRE(newtape2.getIndex() == 3);
    REQUIRE(newtape2.readSymbol() == "1");
}

// 4. Testing the getSize() method
TEST_CASE("Test getSize() for the Tape Class", "[Tape]")
{
    std::vector<std::string> s{"a", "b", "c", "1"};
    Tape toCopyEmpty;
    Tape toCopyCells(s);
    REQUIRE(toCopyEmpty.getSize() == 0);
    REQUIRE(toCopyCells.getSize() == 4);
}

// 5. Testing the getIndex() method
TEST_CASE("Test getIndex() for the Tape Class", "[Tape]")
{
    std::vector<std::string> s{"a", "b", "c", "1"};
    Tape toCopyCells(s);
    REQUIRE(toCopyCells.getIndex() == 0);
    REQUIRE(toCopyCells.readSymbol() == "a");
    toCopyCells.moveRight(); // index should now be 1
    REQUIRE(toCopyCells.getIndex() == 1);
    REQUIRE(toCopyCells.readSymbol() == "b");
    Tape toCopyEmpty;
    REQUIRE(toCopyEmpty.getIndex() == -1); //-1 is returned as toCopyEmpty is empty
}

// 6. Testing the setTape() method
TEST_CASE("Test setTape() for the Tape Class", "[Tape]")
{
    Tape nativeTape;
    std::vector<std::string> s{"a", "X", "B", "e", "5"};
    Tape CopyTape(s);

    // Copying the symbols of CopyTape into nativeTape
    nativeTape.setTape(CopyTape);
    REQUIRE(nativeTape.readSymbol() == "a");
    nativeTape.moveRight();
    REQUIRE(nativeTape.readSymbol() == "X");
    nativeTape.moveRight();
    REQUIRE(nativeTape.readSymbol() == "B");
    nativeTape.moveRight();
    REQUIRE(nativeTape.readSymbol() == "e");
    nativeTape.moveRight();
    REQUIRE(nativeTape.readSymbol() == "5");
}

// 7. Testing the isEmpty() and clear() method
TEST_CASE("Test isEmpty() and clear() for the Tape Class", "[Tape]")
{
    Tape Empty;
    REQUIRE(Empty.isEmpty());
    std::vector<std::string> s{"a", "X", "B", "e", "5"};
    Tape Full(s);
    Full.clear();            //clear the whole tape
    REQUIRE(Full.isEmpty()); //now, full must also be empty
}

// 8. Testing the moveRight() and moveLeft() methods
TEST_CASE("Test moveRight() and moveLeft() for the Tape Class", "[Tape]")
{
    Tape testempty;
    REQUIRE_FALSE(testempty.moveRight());
    REQUIRE_FALSE(testempty.moveLeft());

    std::vector<std::string> s{"a", "b", "c", "1"};
    Tape t(s);
    t.moveRight(); //at index 1

    //index must now be 1, so the symbol at cell 1 must be b
    REQUIRE(t.readSymbol() == "b");

    t.moveRight(); //at index 2
    t.moveRight(); //at index 3

    REQUIRE(t.readSymbol() == "1");

    //^^^ at this step, the machine head should not be able to move to the next cell as we have reached the end of the Tape

    REQUIRE_FALSE(t.moveRight());   //we shouldn't be able to move right as we've reached the end of the tape
    REQUIRE(t.readSymbol() == "1"); //the machine head should still be on the last cell; check if that checks out

    t.moveLeft(); //at index 2
    REQUIRE(t.readSymbol() == "c");

    t.moveLeft(); //at index 1
    t.moveLeft(); //at index 0

    REQUIRE(t.readSymbol() == "a");
    REQUIRE_FALSE(t.moveLeft());    // we shouldn't be able to move left as we've reached the beginning of the tape
    REQUIRE(t.readSymbol() == "a"); //the machine head should still be on the first cell; check if that checks out
}

// 9. Testing the writeBlank() method
TEST_CASE("Test writeBlank() for the Tape Class", "[Tape]")
{
    std::vector<std::string> s{"a", "b", "c", "1"};
    Tape t(s);
    t.moveRight(); //at index 1
    REQUIRE(t.readSymbol() == "b");

    //testing writeSymbol()
    t.writeBlank();
    REQUIRE(t.readSymbol() == " ");
    std::cout << std::endl;
    t.printTape();
}

// 10. Testing the writeSymbol() method
TEST_CASE("Test writeSymbol() for the Tape Class", "[Tape]")
{
    std::vector<std::string> s{"a", "b", "c", "1"};
    Tape t(s);
    t.moveRight(); //at index 1
    REQUIRE(t.readSymbol() == "b");

    //testing writeSymbol()
    t.writeSymbol("L");
    REQUIRE(t.readSymbol() == "L");

    std::cout << std::endl;
    t.printTape();
}

// 10. Testing the readSymbol() method
TEST_CASE("Test readSymbol() for the Tape Class", "[Tape]")
{
    std::vector<std::string> s{"a", "b", "c", "1"};
    Tape t(s);
    REQUIRE(t.readSymbol() == "a");
    t.moveRight(); //at index 1
    REQUIRE(t.readSymbol() == "b");
}

// 12. Testing the printTape() method
TEST_CASE("Test printTape() for the Tape Class", "[Tape]")
{
    std::vector<std::string> s{"a", "b", "c", "1"};
    Tape t(s);
    t.printTape(); //prints the expected cell values in the console window
}

// 13. Testing the rewind() method
TEST_CASE("Test rewind() for the Tape Class", "[Tape]")
{
    std::vector<std::string> s{"a", "b", "c", "1"};
    Tape t(s);
    t.moveRight();
    t.moveRight();
    t.moveRight();
    REQUIRE(t.getIndex() == 3);

    t.rewind();

    REQUIRE(t.getIndex() == 0);
}

// II. TESTING THE TuringMachine CLASS constructors and methods here:

//14. Testing the parameterized constructor, setTape() and setSymbols() methods
TEST_CASE("Test parameterized constructor, setTape and setSymbols methods for the Turing Machine Class", "[TuringMachine]")
{
    std::vector<std::string> s{"a", "b", "c"};
    std::vector<std::string> a{"a", "b", "c", "a", "c"};
    Tape toCopyCells(a);             //creating a tape of cells containing "a", "b", "c", "a", "c"
    TuringMachine t(toCopyCells, s); //using the parameterized constructor

    REQUIRE(t.getSymbols() == s); //testing if the symbols were deep-copied

    int i = 0;

    REQUIRE(t.getTape().readSymbol() == toCopyCells.readSymbol());

    Tape test(t.getTape()); //test Tape

    //testing if the Tape was deep-copied
    while (i < t.getTape().getSize())
    {
        REQUIRE(test.readSymbol() == toCopyCells.readSymbol());
        toCopyCells.moveRight();
        test.moveRight();
        i++;
    }
}

// 15. Testing the getSymbols() methods
TEST_CASE("Test getSymbols() method for the Turing Machine Class", "[TuringMachine]")
{
    TuringMachine t;
    std::vector<std::string> s{"a", "b", "c"};

    t.setSymbols(s);

    REQUIRE(t.getSymbols() == s);
}

// 15. Testing the reset() methods
TEST_CASE("Test reset() method for the Turing Machine Class", "[TuringMachine]")
{
    TuringMachine t;
    std::vector<std::string> s{"a", "b", "c"};
    t.setSymbols(s);
    t.getTape().moveRight();
    t.getTape().moveRight();
    t.getTape().moveRight();

    t.reset();

    REQUIRE(t.getTape().isEmpty());
    REQUIRE(t.getTape().getIndex() == -1); //must return -1 on reset()
}

// 16. Testing the setupCheck() method
TEST_CASE("Test setupCheck() method for the Turing Machine Class", "[TuringMachine]")
{
    TuringMachine t;
    std::vector<std::string> s{"a", "b", "c"};
    t.setSymbols(s);
    REQUIRE(t.setupCheck());
}

// 17. Testing the patternMatch() method
TEST_CASE("Test patternMatch() method for the Turing Machine Class", "[TuringMachine]")
{
    TuringMachine t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12;
    std::vector<std::string> a0{"a", "b", "c"};                     //SHOULD PASS -- 1
    std::vector<std::string> a1{"a", "b", "c", "b", "c"};           //SHOULD NOT PASS
    std::vector<std::string> a2{"a", "b", "b", "b", "c"};           //SHOULD NOT PASS -- EXCESS B THAN C
    std::vector<std::string> a3{"a", "b", "c", "c", "c"};           //SHOULD NOT PASS -- EXCESS C THAN B
    std::vector<std::string> a4{"a", "b", "b"};                     //SHOULD NOT PASS -- INVALID ENTRY
    std::vector<std::string> a5{"a", "b", "x", "c"};                //SHOULD NOT PASS -- INVALID ENTRY
    std::vector<std::string> a6{"a", "b", "b", "c", "c"};           //SHOULD PASS -- 2
    std::vector<std::string> a7{"a", "b", "b", "b", "c", "c", "c"}; //SHOULD PASS -- 3
    std::vector<std::string> a8{"a", "b", "b", "c", "c", "c"};      //SHOULD NOT PASS -- EXCESS C THAN B
    std::vector<std::string> a9{"a", "a", "a"};                     //SHOULD NOT PASS -- ONLY a
    std::vector<std::string> a10{"b", "b", "c", "c"};               //SHOULD NOT PASS -- MISSING a
    std::vector<std::string> a11{"a", "a", "c", "c"};               //SHOULD NOT PASS -- MISSING b
    std::vector<std::string> a12{"a", "a", "b", "b"};               //SHOULD NOT PASS -- MISSING c

    std::vector<std::string> s{"a", "b", "c"};

    Tape tape0(a0);
    Tape tape1(a1);
    Tape tape2(a2);
    Tape tape3(a3);
    Tape tape4(a4);
    Tape tape5(a5);
    Tape tape6(a6);
    Tape tape7(a7);
    Tape tape8(a8);
    Tape tape9(a9);
    Tape tape10(a10);
    Tape tape11(a11);
    Tape tape12(a12);

    t0.setTape(tape0);
    t1.setTape(tape1);
    t2.setTape(tape2);
    t3.setTape(tape3);
    t4.setTape(tape4);
    t5.setTape(tape5);
    t6.setTape(tape6);
    t7.setTape(tape7);
    t8.setTape(tape8);
    t9.setTape(tape9);
    t9.setTape(tape10);
    t9.setTape(tape11);
    t9.setTape(tape12);

    t0.setSymbols(s);
    t1.setSymbols(s);
    t2.setSymbols(s);
    t3.setSymbols(s);
    t4.setSymbols(s);
    t5.setSymbols(s);
    t6.setSymbols(s);
    t7.setSymbols(s);
    t8.setSymbols(s);
    t9.setSymbols(s);
    t10.setSymbols(s);
    t11.setSymbols(s);
    t12.setSymbols(s);

    REQUIRE(t0.setupCheck());
    REQUIRE(t1.setupCheck());
    REQUIRE(t2.setupCheck());
    REQUIRE(t3.setupCheck());
    REQUIRE(t4.setupCheck());
    REQUIRE(t5.setupCheck());
    REQUIRE(t6.setupCheck());
    REQUIRE(t7.setupCheck());
    REQUIRE(t8.setupCheck());
    REQUIRE(t9.setupCheck());
    REQUIRE(t10.setupCheck());
    REQUIRE(t11.setupCheck());
    REQUIRE(t12.setupCheck());

    //TESTING the PatternMatch methods on various Tapes with a different set of symbols
    REQUIRE(t0.patternMatch());
    REQUIRE_FALSE(t1.patternMatch());
    REQUIRE_FALSE(t2.patternMatch());
    REQUIRE_FALSE(t3.patternMatch());
    REQUIRE_FALSE(t4.patternMatch());
    REQUIRE_FALSE(t5.patternMatch());
    REQUIRE(t6.patternMatch());
    REQUIRE(t7.patternMatch());
    REQUIRE_FALSE(t8.patternMatch());
    REQUIRE_FALSE(t9.patternMatch());
    REQUIRE_FALSE(t10.patternMatch());
    REQUIRE_FALSE(t11.patternMatch());
    REQUIRE_FALSE(t12.patternMatch());
}