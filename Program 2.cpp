// Madeline Navarro
// CSC 110 - Introduction to Computing
// Program 2.cpp - Determines whether an entered integer is positive or negative, and whether it is even or odd.
// 3/30/16

#include <iostream>

using namespace std;

int main()
{
	int x,r;
	char ans;

	do
	{
	cout << "Enter an integer: ";
	cin >> x;

	r=x%2;

	if (x < 0)
		cout << x << " is negative" << endl;
	else
		cout << x << " is positive" << endl;

	if (r == 0)
		cout << x << " is even" << endl;
	else
		cout << x << " is odd" << endl;

	cout << "Would you like to enter another number (y or n)? => ";
	cin >> ans;
	} while ((ans == 'y')||(ans == 'Y'));

	cout << "Ok. Goodbye!";

	return 0;
}
