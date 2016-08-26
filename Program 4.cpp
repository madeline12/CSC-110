// Madeline Navarro
// CSC 110
// 5/4/16
// Program 4.cpp - Reads list of input grades and prints grades, average grade, and sum of grades.

#include <iostream>

using namespace std;

void InitArray(double[], int&);                           // Initializes array with input from user
bool InvalidInput();                                      // Checks validity of input grade
double SumArray(const double[], int);                     // Calculates sum of grades and returns result
double AvgArray(double, int);                             // Calculates average of grades and returns result
void PrintGrades(const double[], int, double);            // Prints out grades to user
const int ARRAY_SIZE = 1000;

int main()
{
    int MaxElement;                                       // Declare variables
    double grade[ARRAY_SIZE];                             // initialize size of array
    double sum, avg;

    cout << "Please enter grades below. "                 // Ask user for grades
         << "Input a negative number to stop." << endl;   // Entering a negative number ends input
    InitArray(grade, MaxElement);

    sum = SumArray(grade, MaxElement);                    // Print sum of grades
    cout << "\n\nSum: " << sum;

    avg = AvgArray(sum, MaxElement);                      // Print average grade
    cout << "\n\nAverage: " << avg << "\n\n";

    cout << "Grades: " << endl;                           // Display grades to user
    PrintGrades(grade, MaxElement, avg);                  // If grade is over average, print a star

    return 0;
}

//-----------------------------------------------------------------------------------------------

void InitArray(double someArray[], int& mx)
{
    for (int i=0; i < ARRAY_SIZE; i++)                    // User enters grades to fill array
    {
        do
        {
            cout << "Grade #" << i+1 << ": ";
            cin >> someArray[i];
            cin.ignore(100, '\n');

        } while (!InvalidInput());                        // Calls function to check validity

        if (someArray[i] < 0)                             // A negative number sets the max array element to counter value
        {
            mx = i;
            break;
        }
    }
}

//-----------------------------------------------------------------------------------------------

bool InvalidInput()
{
    if (!cin)                                             // If invalid grade is entered, input is cleared
    {
        cout << "Invalid input. "                         // User is also asked to re-enter grade
             << "Please re-enter grade." << endl;
        cin.clear();
        cin.ignore(100, '\n');
        return false;
    }
    else
        return true;

}

//-----------------------------------------------------------------------------------------------

double SumArray(const double someArray[], int mx)
{
    double sum = 0;                                          // Sum calculation uses max size as indicated by user input of a negative value
    for (int i=0; i<mx; i++)
        sum = sum + someArray[i];

    return sum;
}

//-----------------------------------------------------------------------------------------------

double AvgArray(double sum, int mx)
{
    if (mx != 0)                                             // Calculates average using sum and max size as indicated by user
        return sum/double(mx);
    else                                                     // If no elements in array, average is returned as 0
        return 0;
}

//-----------------------------------------------------------------------------------------------

void PrintGrades(const double someArray[], int mx, double avg)
{
    for (int i=0; i < mx; i++)                            // Function is passed the value of the grade average
    {
        cout << someArray[i];
        if (someArray[i]>avg)                             // If grade is above average, an asterisk is printed beside the grade
            cout << '*';
        cout << endl;
    }
}

//-----------------------------------------------------------------------------------------------
