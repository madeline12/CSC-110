// Madeline Navarro
// CSC 110
// Array In Class.cpp - Creates array of five random integers and displays numbers in reverse order
// 4/20/16

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const int x = 5;   // Constant for array size

    int rdm[x]; // Declare array

    for(int i=0; i<x; i++)
        rdm[i] = rand() % 1000;   // Each integer in array is random

    cout << "Regular order: ";    // Display array is correct order
    for (int i=0; i<x; i++)
        cout << rdm[i] << ' ';

    cout << endl << endl << "Reverse order: ";  // Display array in reverse order
    for (int i=(x-1); i>=0; i--)
        cout << rdm[i] << ' ';
    cout << endl;

    return 0;
}
