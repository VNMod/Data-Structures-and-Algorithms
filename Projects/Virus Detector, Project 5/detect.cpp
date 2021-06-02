// Project: Virus Detector
// Written by Varun Nimish Modak

#include "treap_bst.hpp"
#include <fstream>
#include <string>

// Method Declarations:

// Method to convert a passed ASCII character into its 8-bit (1 byte) binary equivalent [in string format]
std::string ASCIIToBinary(char token);

// Method to sort (in ascending order) the list of viruses stored in a 2-D vector virus
std::vector<std::vector<std::string>> ascendingSort(std::vector<std::vector<std::string>> virus);

// Notes:
/*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/
// command line arguments are passed as parameters to main()
// argc tells main() the number of command line arguments
// argv stores the list of command-line arguments
// so, for ""./detect list binfile": argc is 3 and argv[1] and arv[2] is list and binfile respectively
// argv is the executable being run
// Thus, argv[1] is the file containing the list of viruses [.txt file that contains the list of viruses/malware]
// And, argv[2] is the binary file to be checked for viruses
/*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/

int main(int argc, char *argv[])
{
    // this program should only expect two more arguments (apart from the project name):
    // name of the file containing the list of viruses and the name of the binary file
    // if more than two arguments follow, an exception is thrown!
    if (argc != 3)
    {
        throw std::logic_error("Inaccurate list of commands.");
    }

    std::string list = argv[1];    //obtained from the main as the first argument
    std::string binfile = argv[2]; //obtained from the main as the second argument

    // declaring ifstream object to read from detect.txt
    std::ifstream in(list, std::ios::in);

    // declaring the ifstream object to read from a binary file called binfile.dat
    std::ifstream scan(binfile, std::ios::in | std::ios::binary);

    if (!in) //if this ifstream objects fails to open the appropriate .txt file, an exception is thrown
    {
        throw std::logic_error("Invalid Command Line Arguments! Input valid files");
    }
    else if (!scan) //if this ifstream object fails to open the appropriate binary file, an exception is thrown
    {
        throw std::logic_error("Invalid Command Line Arguments! Input valid Files");
    }

    std::vector<std::vector<std::string>> viruses; //vector to store the list of viruses from the .txt file
    std::string line;                              //string to parse every line of the file
    char blank_space = ' ';

    /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/
    /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/

    // STEP 1: FETCH THE VIRUSES FROM THE .TXT FILE.
    //         THEN, SECURELY STORE THEM IN A VECTOR OF VECTOR OF STRINGS called virus.

    // keep reading from the .txt file while there exists a line in the file to read
    // i.e. till the end of the file
    while (std::getline(in, line))
    {
        int x = 0; //starting position for the first byte of the line
        int i = 0; //position of each character bit of a single byte (an index w.r.t to the fetched line)

        std::vector<std::string> line_of_bytes;

        int line_size = line.size();

        while (i < line_size)
        {
            //End of a byte is reached if a space is encountered
            if (line[i] == blank_space || (i == line_size - 1))
            {
                std::string byte = line.substr(x, 8); //extract 8 characters from position x and store in a "byte" string
                line_of_bytes.push_back(byte);
                x = i + 1; //update the new starting position for the next byte to be read
            }
            i++; //updating the position of the bit of a byte
        }

        viruses.push_back(line_of_bytes); //pushing the byte to a line of bytes, i.e. the virus
    }

    /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/
    /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/

    // STEP 2: SORT THE FOUND LIST OF VIRUSES (IN ASCENDING ORDER) SO THAT THE SEARCH MAY OCCUR ACCORDINGLY
    std::vector<std::vector<std::string>> sorted_viruses = ascendingSort(viruses);

    /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/
    /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/

    // STEP 3: FETCH EACH AND EVERY BYTE FROM THE BINARY FILE & STORE IT IN A SINGLE TREAP

    char token[1];                       //token to parse each ascii character of the binary file
    scan.seekg(0, std::ios::end);        //drag the indexer to the end of the binary file
    const int last_token = scan.tellg(); //store the index of the last character of the file
    scan.seekg(0);                       //now, drag the indexer back to the beginning

    //A treap that should stores each character (on converting it into a byte of binary valued strings) within the file
    TreapBST<int, std::string> binbytes;

    for (int i = 0; i < last_token; i++)
    {
        scan.read(token, 1); //read each ASCII token from the file

        //convert the ASCII token to its 8-bit binary equivalent and store it in a string
        std::string bin_token = ASCIIToBinary(token[0]);

        //now, insert binary strings into a Treap as nodes with keys of consecutive values
        binbytes.insert(i, bin_token);
    }

    /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/
    /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/
    // STEP 4: SCANNING THROUGH THE TREAP AND STORING THE VIRUSES FOUND

    // This is the vector that will store all the viruses that are found after the treap is scanned/searched through
    std::vector<std::vector<std::string>> viruses_found;

    bool flag = false; //essential for Treap searches

    // for every scanned (and sorted) virus
    for (int i = 0; i < sorted_viruses.size(); i++)
    {
        int virus_size = sorted_viruses[i].size();

        bool virus_has_been_found = false; //tracks if that virus has been found

        // scan the Treap for that virus
        for (int j = 0; j <= last_token; j++)
        {
            int next = 0;

            if (sorted_viruses[i].size() == 0) //if a virus of size zero is encountered (break out of this loop)
            {
                break;
            }

            // search the first byte stored in the Treap with key 0 and compare to the first byte of that virus
            if (sorted_viruses[i][0] == binbytes.search(j, flag))
            {
                virus_has_been_found = true; //true so far as the first byte has matched

                //next keeps track of the indices of the bytes of the Treap that
                //follow the j-th byte (node) stored within the Treap
                next = j;

                //now, compare each consecutive byte of that virus with that of the Treap
                for (int k = 1; k < virus_size; k++)
                {
                    next++;
                    if (sorted_viruses[i][k] == binbytes.search(next, flag))
                    {
                        virus_has_been_found = true;
                    }
                    else
                    {
                        virus_has_been_found = false;
                        break;
                    }
                }

                if (virus_has_been_found) //if a virus has been found, add it to the vector of found viruses
                {
                    viruses_found.push_back(sorted_viruses[i]);
                    break;
                }
            }
        }
    }

    /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/
    /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/ /*******/

    // STEP 5: OUTPUTTING THE VIRUSES THAT HAVE BEEN FOUND
    if (viruses_found.size() == 0)
    {
        std::cout << "No viruses/malware found!" << std::endl;
    }
    else
    {
        std::cout << "Viruses/malware found:" << std::endl;
        for (int i = 0; i < viruses_found.size(); i++)
        {
            for (int j = 0; j < viruses_found[i].size(); j++)
            {
                //if not last byte of a virus, print that byte and a single space
                if (j != viruses_found[i].size() - 1)
                {
                    std::cout << viruses_found[i][j] << " ";
                }
                //else if last byte of the virus, print that byte and an endline character
                else
                {
                    std::cout << viruses_found[i][j] << std::endl;
                }
            }
        }
    }
}

// Method to convert a passed ASCII character into its 8-bit (1 byte) binary equivalent in string format
std::string ASCIIToBinary(char token)
{
    std::string binary = "";                 //empty string that will hold the binary equivalent value
    uint8_t token_unsigned = uint8_t(token); //typecasting the passed character to its unsigned integer value

    // standard algorithm for converting a number into binary:
    // keep dividing by 2 and appending the remainder to a number until you reach 0
    // Then, reverse this number to obtain the required equivalent
    // Ex: if you divide 5, you get 5/2 = 2 with a remainder of 1
    //     So, number = 1
    //     now, divide 2/2 = 1 with a remainder of 0
    //     So, number = 10 (as you append 0 to 1)
    //     now, divide 1/2 = 0 with a remainder of 1
    //     So, number = 101 (as you append 1 to 10)
    //     now, the token is 0, so you exit!
    //     THEN, you reverse 101 to get 101 - this is the binary equivalent of 5

    while (token_unsigned > 0)
    {
        if (token_unsigned % 2)
        {
            binary.append("1");
        }
        else
        {
            binary.append("0");
        }

        token_unsigned = token_unsigned / 2;
    }

    // Now, you reverse the obtained number to get the binary equivalent
    reverse(binary.begin(), binary.end());

    // Now, the binary equivalent you obtain may not be 8-bits long
    // So, you make it a byte long by adding 0s to the beginning of the string

    for (int i = 0; binary.size() < 8; i++)
    {
        binary = '0' + binary;
    }

    //now, we return the 8-bit long binary equivalent of the single ASCII character parameter
    return binary;
}

// Method to sort (in ascending order) the list of viruses stored in the 2-D vector virus
// Returns the sorted list of viruses (in a vector of vector of strings)
std::vector<std::vector<std::string>> ascendingSort(std::vector<std::vector<std::string>> virus)
{
    // Creates a vector of boolean values that keep track of which elements have been visited & sorted
    std::vector<bool> sorted(virus.size(), false);

    //create a vector for sorted viruses of the size of the vector storing a list of viruses
    std::vector<std::vector<std::string>> sorted_virus(virus.size());

    int virus_size = virus.size();

    for (int i = 0; i < virus_size; i++)
    {
        int min_size = virus[i].size(); //let the min_size be the size of the i-th virus

        int sorted_index;

        bool first_min = false;

        // finding the next minimum size - traverses through each unvisited/unsorted element
        // to determine the next minimum size
        for (int k = 0; k < virus.size(); k++)
        {
            // finding the first unsorted size encountered.
            // this is essential as the rest of the viruses of greater sizes need to be added
            // to the finally sorted virus. Thus, this allows us to set sorted_index to the indices
            // of the unadded viruses so that they may be added once the viruses of min_sizes have been added.
            if (!sorted[k] && !first_min) //if that particular element hasn't been sorted
            {
                min_size = virus[k].size();
                sorted_index = k;
                first_min = true;
            }

            // Setting min_size with the minimum size value and storing the index of that virus in sorted_index
            if (virus[k].size() < min_size && !sorted[k])
            {
                min_size = virus[k].size();
                sorted_index = k;
            }
        }

        sorted[sorted_index] = true;
        sorted_virus[i] = virus[sorted_index];
    }

    return sorted_virus;
}