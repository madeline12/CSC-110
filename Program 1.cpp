//**************************************************************************************
// Madeline Navarro
// Date last updated: 9/13/2016
// Version 1.1
// Chessboard Program Edit
// This is an update to the Chessboard program made to build a pattern made of strings
// of black and white characters.
//**************************************************************************************
#include <iostream>

using namespace std;

const string BLACK = "********";	// Define black square line
const string WHITE = "        ";	// Define white square line
const string BORDER = "________";	// Define border square line

string InitRow(string, string);		// Function to initialize a row with two colors
void PrintBlock(string);			// Function to print 5 rows to make a block

//**************************************************************************************

int main()
{
    string whiteRow;
    string blackRow;
    string borderRow;

	// For the white row, the white block is input first then the black
	// For the black row, the black block is input first then the white
	// For the border row, two border block are input
    whiteRow = "|" + InitRow(WHITE, BLACK) + "|";
    blackRow = "|" + InitRow(BLACK, WHITE) + "|";
    borderRow = InitRow(BORDER, BORDER);

	// Top border does not need side borders
    cout << " " + borderRow + " " << endl;

	// Pattern of one color then the other is repeated four times to get a square board
	for (int i=0; i<4; i++)
	{
		PrintBlock(whiteRow);
		PrintBlock(blackRow);
	}

	// Bottom border requires side borders
    cout << "|" + borderRow + "|" << endl;
	
    return 0;
}

//**************************************************************************************

// Initalize Row Function
// Initialize a row; the first color is included before the second color
//
// Inputs: First color, second color
// Outputs: Initialized row of input colors
string InitRow(string color1, string color2)
{
    string someRow = color1 + color2;
    for (int i=0; i<3; i++)
        someRow += color1 + color2;
    return someRow;
}

//**************************************************************************************

// Print Row of Squares Function
// Print a block; each row of one color must be printed 5 times to make a whole block
//
// Inputs: Row of colored lines
// Outputs: Row of colored squares
void PrintBlock(string someRow)
{
	for (int i=0; i<5; i++)
		cout << someRow << endl;
}

//**************************************************************************************
