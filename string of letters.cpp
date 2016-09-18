//---------------------------------------------------------------------------------------------------
// CSC 201 - Computer Science I
// Name:        Madeline Navarro
// Date:        9/13/16
// Inputs:      String of letters
// Outputs:     String with anything not a letter removed
// Description: Checks the validity of a string of characters
//              If not all letters, the non-letters are removed from the string
//
//---------------------------------------------------------------------------------------------------

#include <iostream>          // Header including cin and cout
#include <cctype>            // Header including toupper
#include <string>            // Header including string functions

using namespace std;


int main()
{
    string x;

    cout << "x: ";
    cin >> x;

    for (int i=0; i<x.length();i++)
    {
        if (!isalpha(x[i]))
        {
            if (i+1 > x.length())
                x = x.substr(0,i);
            else
                x = x.substr(0,i)+x.substr(i+1, x.length());
            i--;
        }
    }

    cout << x;

    return 0;
}
