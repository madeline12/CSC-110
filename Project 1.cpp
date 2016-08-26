// Madeline Navarro
// CSC 110 - Introduction to Computing
// 2/29/2016
// Project 1 - Calculating miles per gallon given miles driven and gallons used

#include <iostream>
#include <iomanip>

using namespace std;

const float KM_PER_MILE = 1.60934;
const float L_PER_GALLON = 3.78541;

int main()
{
    float milesDriven;
    float gallonsUsed;
    float milesPerGallon;

    cout << "Enter the number of miles driven: ";
    cin >> milesDriven;

    cout << "Enter gallons of gas used: ";
    cin >> gallonsUsed;

    cout << fixed << setprecision(2) << endl;

    if (milesDriven<0||gallonsUsed<0||milesPerGallon<0)
        {
        cout << "Error. Please enter positive values." << endl;

        return 1;
        }

    milesPerGallon = milesDriven/gallonsUsed;
    cout << "Distance traveled: \n\t" << milesDriven << " miles" << "\n\t"
         << (milesDriven*KM_PER_MILE) << " kilometers" << endl << endl;
    cout << "Gas used: \n\t" << gallonsUsed << " gallons" << "\n\t"
         << (gallonsUsed*L_PER_GALLON) << " liters" << endl << endl;

    cout << "Fuel efficiency: \n\t" << milesPerGallon << " miles per gallon" << "\n\t"
         << ((milesPerGallon*KM_PER_MILE)/L_PER_GALLON) << " kilometers per liter" << endl;


    return 0;
}
