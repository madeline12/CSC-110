#include <iostream>

using namespace std;

int main()
{
    int n;

    for (int i=0; n!=5 && i < 10; i++)
    {
        cout << "Enter any number other than 5: ";
        cin >> n;
    }

    if (n==5)
    {
        cout << endl << "Hey! I told you not to enter 5!" << endl;
        return 1;
    }

    cout << endl << "Wow, you have more patience than I do, you win." << endl;

    return 0;
}
