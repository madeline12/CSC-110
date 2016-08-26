// Madeline Navarro
// Cola Machine (1)

#include <iostream>
#include <cctype>

using namespace std;

void DrinkOutput(int);

int main()
{
	int drink;
	char ans;
	
	do
	{
		cout << "VENDING MACHINE" << endl
			 << "(1) Coffee" << endl << "(2) Hot Chocolate"
			 << endl << "(3) Green Tea" << endl
			 << "(4) Juice" << endl << "(5) Milk\n\n";
			 
		cout << "Please choose your beverage (1, 2, 3, 4, 5) => ";
		cin >> drink;
		cin.ignore(100, '\n');
		cout << endl;
		
		DrinkOutput(drink);
		
		do
		{
			cout << "Would you like to choose another drink? (Y/N) ";
			cin >> ans;
			cin.ignore(100, '\n');
			ans = toupper(ans);
		} while (ans != 'Y' && ans != 'N');
		
		cout << endl;
		
	} while (ans == 'Y');
	
	cout << "Please come back soon!";
	return 0;
}

void DrinkOutput(int B)
{
	switch (B)
	{
		case 1:
			cout << "Your choice is Coffee. Cream and sugar not included.";
			break;
		case 2: 
			cout << "Your choice is Hot Chocolate. Let it cool first, Sonic.";
			break;
		case 3:
			cout << "Your choice is Green Tea. Served in proper traditional style.";
			break;
		case 4:
			cout << "Your choice is Juice. You don't know what kind of juice it is.";
			break;
		case 5:
			cout << "Your choice is Milk. I hope the vending machine is refridgerated.";
			break;
		default:
			cout << "Error. Here is your money back...?";
			cin.clear();
			cin.ignore(100, '\n');
			break;
	}
	cout << endl << endl;
}
