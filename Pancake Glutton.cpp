#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int pancakes[10];
    int ppl[10] = {1,2,3,4,5,6,7,8,9,10};
    int maxPancakes = 0;

    for(int x=0; x<10; x++)
    {
        cout << "Enter the number of pancakes eaten by person " << ppl[x] << ": ";
        cin >> pancakes[x];

    }

    for (int x=0; x<10; x++)
        cout << "Person " << ppl[x] << ": " << pancakes[x] << " pancakes" << endl;

    int mn, mx;
    int pplMax, pplMin;

    mn = pancakes[0];
    mx = pancakes[0];
    pplMax = ppl[0];
    pplMin = ppl[0];

    for (int x=0; x<10; x++)
    {
        if (mn > pancakes[x])
            {
                mn = pancakes[x];
                pplMin = ppl[x];
            }
        else if (mx < pancakes[x])
            {
                mx = pancakes[x];
                pplMax = ppl[x];
            }
    }

    cout << "\nPerson " << pplMax << ": " << mx << " pancakes" << endl;
    cout << "Person " << pplMin << ": " << mn << " pancakes\n\n" << endl;

    for (int x=0; x<10; x++)
    {
        for (int n=0; n<10; n++)
        {
            if (pancakes[x] > pancakes[n])
            {
                int buffer = pancakes[x];
                pancakes[x] = pancakes[n];
                pancakes[n] = buffer;
                buffer = ppl[x];
                ppl[x] = ppl[n];
                ppl[n] = buffer;
            }
        }
    }

    for (int x=0; x<10; x++)
    {
        cout << "Person " << ppl[x] << ": " << pancakes[x] << " pancakes" << endl;
    }

    cout << endl;

    return 0;
}
