//---------------------------------------------------------------------------------------------------
// CSC 201 - Computer Science I
// Group #3: Jeremy, Madeline, Eddie, Hieu, Robert
// Date: 9/13/16
// Inputs: Input file name
// Outputs: First line of file encoded, output file with encoded text
// Description: Given a string that is obtained from an input file, this program converts the string
// 				using a cipher. The cipher replaces each letter with the letter that is 13 letters
// 				after it in the alphabet.
// 				Example: COMPUTER ==> PBZCHGRE
//---------------------------------------------------------------------------------------------------

#include <iostream>          // Header including cin and cout
#include <fstream>           // Header including ifstream and ofstream
#include <cctype>            // Header including toupper
#include <string>            // Header including string functions

using namespace std;

void ROT13(string, string&); // Rotates each letter 13 spaces in the alphabet (ex. A => N)

int main()
{
    // Declare variables
    string inFile;			 // Name for input file
    string word;
	
	// Give user directions and notify of invalid character display
    cout << "Please enter letters and spaces only. Anything is not a letter will be indicated by *." << endl;
    
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
// Outputs: Encoded string, output file "file.rot13"

void ROT13(string fileName, string& word)
{
    // Declaring and opening files
    ifstream inData(fileName.c_str());
    ofstream outData("file.rot13");
    
	// Only executes main body of function if files are both open
    if (inData && outData)
    {
    	// Get the first line of the input file
        getline(inData,word);

        for (int i=0; i<word.length(); i++) 	 // Converts letters for entire length of line
        {
            word[i]=toupper(word[i]); 			 // Converts each letter to uppercase	

            if (word[i]>=65 && word[i]<78) 	 // Checking for values between A - M on ASCII table
                word[i]+=13;
            else if (word[i]>=78 && word[i] <=90) // Checking for values between N - Z on ASCII table
                word[i]-=13;
            else if (word[i]==32) 				 // Creates an exception for spaces
                continue;
            else
                word[i]='*'; 					 // Changes invalid character inputs to a "*"
        }
        
        // Display encrypted string to user so the user can check input
		cout << "Encrypted string: "<< word << endl;
		
		// Send encrypted string to output file
        outData << word;
    }
    else
        cout << "Invalid file.";	// If either file is in the fail state, output error message
	
	// Close both files
    inData.close();
    outData.close();

}
