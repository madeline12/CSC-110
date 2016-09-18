//---------------------------------------------------------------------------------------------------
// CSC 201 - Computer Science I
// Group #3: Jeremy, Madeline, Eddie, Hieu, Robert
// Version: 2.0
// Name: Madeline Navarro
// Date: 9/19/16
// Inputs: Input file name
// Outputs: First line of file encoded, output file with encoded text
// Description: Given a string that is obtained from an input file, this program converts the string
// 				using a cipher. The cipher replaces each letter with the letter that is 13 letters
// 				after it in the alphabet.
// 				Example: COMPUTER ==> PBZCHGRE
//---------------------------------------------------------------------------------------------------

#include <iostream>          // Header including cin and cout
#include <fstream>           // Header including ifstream and ofstream
#include <cctype>            // Header including char functions
#include <string>            // Header including string functions

using namespace std;

void ROT13(string, string&); // Rotates each letter 13 spaces in the alphabet (ex. A => N)

int main()
{
    // Declare variables
    string inFile;			 // Name for input file
    string word;

	// Give user directions and notify of invalid character display
    cout << "Please enter letters and spaces only. "
         << "Anything not a letter or a space will be removed." << endl;

	// Ask the user for the input file name
	cout << "Please enter the name of an existing text file: ";
    cin >> inFile;

    // Call rotate 13 function
    ROT13(inFile, word);

    return 0;
}

//---------------------------------------------------------------------------------------------------
// Rotate 13 Letters Function
// This function uses the input string name as the input file and "file.rot13" as the output file
// and uses the first line of the input file to be encoded. The encrypted string is then sent to
// the open output file.
//
// Inputs: Name of input file
// Outputs: Encoded file, output file "file.rot13"

void ROT13(string fileName, string& line)
{
    // Declaring and opening files
    ifstream inData(fileName.c_str());
    ofstream outData("file.rot13");

	// Only executes main body of function if files are both open
    if (inData && outData)
    {
        int c = 0;                                    // Initialize output letter counter c

        while (getline(inData,line))                  // Get line of input file until it ends
        {
            for (int i=0; i<line.length(); i++) 	  // Converts letters for entire length of line
            {
                if (isalpha(line[i]))
                {
                    if (line[i]<'N') 	              // If char is between 'A' and 'M' on ASCII table
                        line[i]+=13;
                    else if (line[i]<='Z')            // If char is between 'N' and 'Z' on ASCII table
                        line[i]-=13;
                    else if (line[i]<'n')             // If char is between 'a' and 'm' on ASCII table
                        line[i]+=13;
                    else
                        line[i]-=13;                  // If char is between 'n' and 'z' on ASCII table
                    c++;
                }
                else if (isspace(line[i])) 			  // Creates an exception for spaces
                    continue;
                else                                  // Anything not a letter or space is removed
                    {
                        if (i+1 > line.length())
                            line = line.substr(0,i);    // If non-letter is beyond line length, remove from end
                        else                            // If non-letter is within line, set line to everything except invalid char
                            line = line.substr(0,i) + line.substr(i+1, line.length());
                        i--;                            // Length of string changed, so iteration i must be updated
                    }
                if (c == 50)                          // If counter c reaches 50, send rest of char in current line
                {
                    line = line.substr(0,i+1);
                    break;
                }
            }

            // Display encrypted file to user so the user can check input
            cout << line << endl;

            // Send encrypted string to output file
            outData << line << '\n';

            if (c == 50)    // If counter c reaches 50, exit file input
                break;
        }

    }
    else
        cout << "Invalid file.";	// If either file is in the fail state, output error message

	// Close both files
    inData.close();
    outData.close();

}
