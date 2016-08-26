

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    int x, mx;

    cout << "Enter how many random numbers to generate: ";
    cin >> x;

    cout << "Enter the maximum number: ";
    cin >> mx;
    cout << endl;

    srand(time(NULL));

    int n = 0;

    while (n<x)
    {
        cout << (rand() % mx) + 1 << " ";
        cout << endl;

        n++;
    }

    return 0;
}
