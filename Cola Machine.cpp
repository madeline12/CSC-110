#include <iostream>

using namespace std;

int main()
{
    int drink;

    cout << "Pick your favorite beverage of the following: " << endl
         << "1) Coke" << endl << "2) Coffee" << endl
         << "3) Hot chocolate" << endl << "4) Juice"
         << endl << "5) Milk" << endl << endl;

    cin >> drink;

    switch (drink)
    {
    case 1:
        cout << endl << "Your drink of choice is Coke.";
        break;
    case 2:
        cout << endl << "Your drink of choice is coffee.";
        break;
    case 3:
        cout << endl << "Your drink of choice is hot chocolate.";
        break;
    case 4:
        cout << endl << "Your drink of choice is juice.";
        break;
    case 5:
        cout << endl << "Your drink of choice is milk.";
        break;
    default:
        cout << endl << "Error. Choice was not valid, here is your money back.";
    }

    cout << endl;

    return 0;
}
