// Madeline Navarro
// CSC 110
// 4/25/16
// Assignment 11.cpp - Fills two arrays with five input values. Displays sum and average of each array. Compares if arrays are equivalent.

#include <iostream>

using namespace std;

void InitArray(float[], int, bool&);     		    	// Fills array with user entered values
void SumArray(const float[], int, float&);			    // Calculates sum of entered array
void PrintArray(const float[], int); 					// Prints the contents of entered array
bool CompareArrays(const float[], const float[], int);	// Compares if two arrays contain equivalent elements
const int ARRAY_SIZE = 5;

int main()
{
    // Declare variables, set array size to 5

    float array1[ARRAY_SIZE];
    float array2[ARRAY_SIZE];
    float sum1, sum2;
    sum1 = 0;
    sum2 = 0;
    bool flag = true;

    // Ask user to fill arrays
    cout << "Input five values for the first array." << endl;
    InitArray(array1, ARRAY_SIZE, flag);

    cout << "Input five values for the second array." << endl;
    InitArray(array2, ARRAY_SIZE, flag);


	// Display arrays
	cout << "\nArray #1: ";
	PrintArray(array1, ARRAY_SIZE);

	cout << "Array #2:";
	PrintArray(array2, ARRAY_SIZE);


    // Calculate sum of arrays and display to user
    SumArray(array1, ARRAY_SIZE, sum1);
    SumArray(array2, ARRAY_SIZE, sum2);

    cout << "\nSum of first array: " << sum1 << endl;
    cout << "Sum of second array: " << sum2 << endl;

    cout << endl;
    flag = CompareArrays(array1, array2, ARRAY_SIZE);
    if (flag)
    	cout << "The two arrays are equivalent.";
	else
		cout << "The two arrays are not equivalent.";
    cout << endl;

    return 0;
}

void InitArray(float someArray[], const int mx, bool& flag)
{
    for (int i=0; i<mx; i++)
    {
        do
        {
            cout << "Enter #" << i+1 << ": ";
            cin >> someArray[i];

            if (!cin)
            {
                cout << "Invalid input." << endl;
                cin.clear();
                cin.ignore(100, '\n');
                flag = false;
                continue;
            }
            else
                flag = true;
        } while (!flag);
    }
}

void SumArray(const float someArray[], int mx, float& sum)
{
    for (int i=0; i<mx; i++)
    {
        sum = sum + someArray[i];
    }
}

void PrintArray(const float someArray[], int mx)
{
	cout << "{ ";
	for (int i=0; i<mx; i++)
    {
        cout << someArray[i] << ' ';
    }
    cout << '}' << endl;
}

bool CompareArrays(const float firstArray[], const float secondArray[], int mx)
{
	for (int i=0; i<mx; i++)
	{
		if (firstArray[i] != secondArray[i])
			return false;
	}
	return true;
}
