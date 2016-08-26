#include <iostream>

using namespace std;

int main()
{
    int grade;

    cout << "Please enter your grade: ";
    cin >> grade;
    cout << endl;

    if (grade < 0)
        cout << "Invalid grade. Please enter a positive value." << endl;
    else if (grade < 60)
        cout << "You got an F. You FAILED" << endl;
    else if (grade < 70)
        cout << "You got a D. You should study." << endl;
    else if (grade < 80)
        cout << "You got a C. You should study more." << endl;
    else if (grade < 90)
        cout << "You got a B. You did all right." << endl;
    else if (grade < 100)
        cout << "You got an A. You did well." << endl;
    else if (grade == 100)
        cout << "You got a perfect score!" << endl;

    return 0;
}
