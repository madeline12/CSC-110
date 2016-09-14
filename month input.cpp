#include <iostream>

#include <cmath>
#include <iomanip>

#include <cctype>
#include <string>

using namespace std;

int main()
{
    int month1, month2, day1, day2, year1, year2, daysElapsed;
    int days1=0, days2=0, FebDays1=28, FebDays2=28;
    string mon1, mon2;
    bool flag;

    cout << "Please enter the first date." << endl
         << "Example: May 2 1997" << endl;

    do
    {
        cout << "Date: ";
        cin >> mon1 >> day1 >> year1;

        if (!cin)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Please enter a proper date." << endl;
            flag = false;
            continue;
        }
        flag = true;

        mon1[0]=toupper(mon1[0]);
        for (int i=1; i<mon1.length(); i++)
            mon1[i]=tolower(mon1[i]);

        if (mon1=="January")
            month1=1;
        else if (mon1=="February")
            month1=2;
        else if (mon1=="March")
            month1=3;
        else if (mon1=="April")
            month1=4;
        else if (mon1=="May")
            month1=5;
        else if (mon1=="June")
            month1=6;
        else if (mon1=="July")
            month1=7;
        else if (mon1=="August")
            month1=8;
        else if (mon1=="September")
            month1=9;
        else if (mon1=="October")
            month1=10;
        else if (mon1=="November")
            month1=11;
        else if (mon1=="December")
            month1=12;
        else
        {
            month1=99;
            cout << "Invalid month. Please enter a proper month name." << endl;
        }
    } while (!flag || month1==99);

    if (year1%4==0)
        if (year1%100!=0)
            FebDays1=29;
    else if (year1%400==0)
        FebDays1=29;

    switch (month1)
    {
        case 12:
            days1+=30;
        case 11:
            days1+=31;
        case 10:
            days1+=30;
        case 9:
            days1+=31;
        case 8:
            days1+=31;
        case 7:
            days1+=30;
        case 6:
            days1+=31;
        case 5:
            days1+=30;
        case 4:
            days1+=31;
        case 3:
            days1+=FebDays1;
        case 2:
            days1+=31;
        case 1:
            break;
    }

    cout << "Please enter the second date." << endl;

        do
    {
        cout << "Date: ";
        cin >> mon2 >> day2 >> year2;

        if (!cin)
        {
            cin.clear();
            cin.ignore(100, '\n');
            cout << "Invalid input. Please enter a proper date." << endl;
            flag = false;
            continue;
        }
        flag = true;

        mon2[0]=toupper(mon2[0]);
        for (int i=1; i<mon2.length(); i++)
            mon2[i]=tolower(mon2[i]);

        if (mon2=="January")
            month2=1;
        else if (mon2=="February")
            month2=2;
        else if (mon2=="March")
            month2=3;
        else if (mon2=="April")
            month2=4;
        else if (mon2=="May")
            month2=5;
        else if (mon2=="June")
            month2=6;
        else if (mon2=="July")
            month2=7;
        else if (mon2=="August")
            month2=8;
        else if (mon2=="September")
            month2=9;
        else if (mon2=="October")
            month2=10;
        else if (mon2=="November")
            month2=11;
        else if (mon2=="December")
            month2=12;
        else
        {
            month2=99;
            cout << "Invalid month. Please enter a proper month name." << endl;
        }
    } while (!flag || month2==99);

    if (year2%4==0)
        if (year2%100!=0)
            FebDays2=29;
    else if (year2%400==0)
        FebDays2=29;

    switch (month2)
    {
        case 12:
            days2+=30;
        case 11:
            days2+=31;
        case 10:
            days2+=30;
        case 9:
            days2+=31;
        case 8:
            days2+=31;
        case 7:
            days2+=30;
        case 6:
            days2+=31;
        case 5:
            days2+=30;
        case 4:
            days2+=31;
        case 3:
            days2+=FebDays2;
        case 2:
            days2+=31;
        case 1:
            break;
    }

    days1+=day1;
    days2+=day2;
    cout << "The day " << month1 << '/' << day1 << '/' << year1 << " is day number " << days1 << " of the year.\n";
    cout << "The day " << month2 << '/' << day2 << '/' << year2 << " is day number " << days2 << " of the year.\n\n";


    daysElapsed = days2 - days1;




	if (year2 > year1)
			for (int i=year1; i<year2; i++)
			{
				if (i%4==0 && i%100 !=0)
					daysElapsed++;
				else if (i%400==0)
					daysElapsed++;
				daysElapsed += 365;
			}
	else if (year2 < year1)
			for (int i=year2; i<year1; i++)
			{
				if (i%4==0 && i%100 !=0)
					daysElapsed--;
				else if (i%400==0)
					daysElapsed--;
				daysElapsed = 365 - daysElapsed;
				daysElapsed = -daysElapsed;
			} 

    cout << "The number of days elapsed between the two days: " << daysElapsed;


    return 0;
}
