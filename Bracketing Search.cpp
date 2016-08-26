#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));

    int n, nGuess;

    n = (rand() % 100)+1;

    cout << "A random number has been calculated." << endl
         << "Guess the number: ";
    cin >> nGuess;

    do {
    while (nGuess > n)
    {
        cout << "Too high. Guess again: ";
        cin >> nGuess;
    }

    while (nGuess < n)
    {
        cout << "Too low. Guess again: ";
        cin >> nGuess;
    }
    } while (nGuess != n);

    cout << endl << "You got it!";

    return 0;
}
