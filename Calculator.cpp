// Madeline Navarro
// CSC 110 - Introduction to Computing
// Calculator.cpp
// 3/23/16


#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    // Define variables

    float x1, x2, x3;
    char op;
    char ans;
    bool flag = true;
    // Loop until user wants to stop

    do {

    // Ask user to enter two numbers

    cout << "Enter the first number: ";
    cin >> x1;
    cout << "\nEnter the second number: ";
    cin >> x2;

    if (!cin)
    {
        cout << "\n\nInvalid input.\n\n";
        cin.clear();
        cin.ignore(100, '\n');
        ans = 'Y';
        continue;
    }

    // Ask user for operation

    cout << "\nEnter which operation you would like to use with the two numbers (+, -, *, /) : ";
    cin >> op;

    // Calculate result based on user-entered operation

    switch (op)
    {
    case '+':
        x3 = x1 + x2;
        break;
    case '-':
        x3 = x1 - x2;
        break;
    case '*':
        x3 = x1 * x2;
        break;
    case '/':
        x3 = x1 / x2;
        break;
    default:
        cout << "\nPlease enter +, -, *, /\n\n";
        flag = false;
        break;
    }

    // Display result
    if (flag)
    cout << "\nResult: " << x3 << endl;

    // Ask user if they want to repeat/continue
    // Loop if user says yes

    cout << endl << "Would you like to perform another calculation (y/n)? => ";
    cin >> ans;
    ans = toupper(ans);
    cout << endl;
    }

    while (ans == 'Y');

    cout << endl << "Goodbye!";

    return 0;
}
