




#include <iostream>

#include <cmath>
#include <iomanip>

#include <cctype>
#include <string>

#include <cstdlib>

using namespace std;

int main()
{
    int initMonth, finMonth, initDay=0, finDay=0, initYear, finYear;
    int days1=0, days2=0, daysElapsed, FebDays1=28, FebDays2=28;
    string initMonthName, finMonthName;
    
    int initMeter, finMeter;
    char initString[5], finString[5];
    
    char yesNo;
    float lateMonthBill;
    
    int gasUsed;
    float gasCost;
    
    float totalCharges, costBeforeTax, avgDailyCost;
    
    bool flag1, flag2;

//--------------------------------------------------------------------------------------
// PROJECT TITLE AND DESCRIPTION
//--------------------------------------------------------------------------------------


    cout << "Programming Project #1" << endl
    	 << "----------------------" << endl;
    cout << "This program calculates the monthly natural gas bill based on input information "
		 << "and displays all relevant information to the user.\n\n";

    cout << "Please enter the initial and final date of the billing period." << endl
         << "Example: May 1 2001" << endl;

//--------------------------------------------------------------------------------------
// DATES
//--------------------------------------------------------------------------------------


    do
    {
    	flag2 = true;
        do
        {
        	flag1 = true;
        	
            cout << "Initial date: ";
            cin >> initMonthName >> initDay >> initYear;

            if (!cin)
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid input. Please enter a proper date." << endl;
                flag1 = false;
                continue;
            }

            initMonthName[0]=toupper(initMonthName[0]);
            for (int i=1; i<initMonthName.length(); i++)
                initMonthName[i]=tolower(initMonthName[i]);

            if (initMonthName=="January")
                initMonth=1;
            else if (initMonthName=="February")
                initMonth=2;
            else if (initMonthName=="March")
                initMonth=3;
            else if (initMonthName=="April")
                initMonth=4;
            else if (initMonthName=="May")
                initMonth=5;
            else if (initMonthName=="June")
                initMonth=6;
            else if (initMonthName=="July")
                initMonth=7;
            else if (initMonthName=="August")
                initMonth=8;
            else if (initMonthName=="September")
                initMonth=9;
            else if (initMonthName=="October")
                initMonth=10;
            else if (initMonthName=="November")
                initMonth=11;
            else if (initMonthName=="December")
                initMonth=12;
            else
            {
                flag1 = false;
                cout << "Invalid month. Please enter a proper month name." << endl;
                continue;
            }


            switch (initMonth)
            {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    if (initDay > 31 || initDay < 1)
                        flag1 = false;
                        break;
                case 4: case 6: case 9: case 11:
                    if (initDay > 30 || initDay < 1)
                        flag1 = false;
                        break;
                case 2:
                    if (initDay > FebDays1 || initDay < 1)
                        flag1 = false;
                        break;
            }

            if (!flag1)
                cout << "Invalid data. Please enter a proper amount of days. " << endl;


        } while (!flag1);


        do
        {
        	flag1 = true;
        	
            cout << "Final date: ";
            cin >> finMonthName >> finDay >> finYear;

            if (!cin)
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Invalid input. Please enter a proper date." << endl;
                flag1 = false;
                continue;
            }

            finMonthName[0]=toupper(finMonthName[0]);
            for (int i=1; i<finMonthName.length(); i++)
                finMonthName[i]=tolower(finMonthName[i]);

            if (finMonthName=="January")
                finMonth=1;
            else if (finMonthName=="February")
                finMonth=2;
            else if (finMonthName=="March")
                finMonth=3;
            else if (finMonthName=="April")
                finMonth=4;
            else if (finMonthName=="May")
                finMonth=5;
            else if (finMonthName=="June")
                finMonth=6;
            else if (finMonthName=="July")
                finMonth=7;
            else if (finMonthName=="August")
                finMonth=8;
            else if (finMonthName=="September")
                finMonth=9;
            else if (finMonthName=="October")
                finMonth=10;
            else if (finMonthName=="November")
                finMonth=11;
            else if (finMonthName=="December")
                finMonth=12;
            else
            {
                flag1 = false;
                cin.ignore(100, '\n');
        		cin.clear();
                cout << "Invalid month. Please enter a proper month name." << endl;
                continue;
            }


            switch (finMonth)
            {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    if (finDay > 31 || finDay < 1)
                        flag1 = false;
                        break;
                case 4: case 6: case 9: case 11:
                    if (finDay > 30 || finDay < 1)
                        flag1 = false;
                        break;
                case 2:
                    if (finDay > FebDays2 || finDay < 1)
                        flag1 = false;
                        break;
            }

            if (!flag1)
                cout << "Invalid data. Please enter a proper date. " << endl;

        } while (!flag1);




        if (initYear%4==0 && initYear%100!=0)
            FebDays1=29;
        else if (initYear%400==0)
            FebDays1=29;

        switch (initMonth)
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

        if (finYear%4==0 && finYear%100!=0)
            FebDays2=29;
        else if (finYear%400==0)
            FebDays2=29;

        switch (finMonth)
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

        days1 += initDay;
        days2 += finDay;
        
        daysElapsed = days2 - days1;

		if (finYear > initYear)
			for (int i=initYear; i<finYear; i++)
			{
				if (i%4==0 && i%100 !=0)
					daysElapsed++;
				else if (i%400==0)
					daysElapsed++;
				daysElapsed += 365;
			}
		else if (finYear < initYear)
			for (int i=finYear; i<initYear; i++)
			{
				if (i%4==0 && i%100 !=0)
					daysElapsed--;
				else if (i%400==0)
					daysElapsed--;
				daysElapsed = 365 - daysElapsed;
				daysElapsed = -daysElapsed;
			} 
		
		
        if (daysElapsed<26 || daysElapsed>35)
        {
        	cin.ignore(100, '\n');
        	cin.clear();
            cout << "Invalid data. Billing period should be between 26 and 35 days." << endl;
            flag2 = false;
            continue;
        }    

    } while (!flag2);

//--------------------------------------------------------------------------------------
// METER READINGS
//--------------------------------------------------------------------------------------

	cout << "Please enter initial and final meter readings." << endl
		 << "Readings are 5 digits measured in CCF. Include leading zeros." << endl;
	do
	{
		flag1 = true;
		cout << "Initial meter reading: ";
		cin >> initString;
		
		for (int i=0; i<5; i++)
			if (!isdigit(initString[i]))
			{
				cin.ignore(100, '\n');
        		cin.clear();
				cout << "Invalid input. Please enter a 5 digit number "
					 << "between 00000 and 99999." << endl;
				flag1 = false;
				break;
			}
		if (!flag1)
			continue;
		
		initMeter = atoi(initString);
		
		if (initMeter < 0 || initMeter > 99999)
		{
			cin.ignore(100, '\n');
        	cin.clear();
			cout << "Invalid input. Please enter a 5 digit number "
				 << "between 00000 and 99999." << endl;
	    	flag1 = false;
			continue;
		}
	} while (!flag1);

    do
	{
		flag1 = true;
		cout << "Final meter reading: ";
		cin >> finString;
		
		for (int i=0; i<5; i++)
			if (!isdigit(finString[i]))
			{
				cin.ignore(100, '\n');
        		cin.clear();
				cout << "Invalid input. Please enter a 5 digit number "
				 	 << "between 00000 and 99999." << endl;
				flag1 = false;
				break;
			}
		if (!flag1)
			continue;
		
		finMeter = atoi(finString);
		
		if (finMeter < 0 || finMeter > 99999)
		{
			cin.ignore(100, '\n');
        	cin.clear();
			cout << "Invalid input. Please enter a 5 digit number "
				 << "between 00000 and 99999." << endl;
	    	flag1 = false;
			continue;
		}
	} while (!flag1);

    gasUsed = finMeter - initMeter;

    if (gasUsed < 0)
        gasUsed+=100000;

//--------------------------------------------------------------------------------------
// GAS COST
//--------------------------------------------------------------------------------------

    if (gasUsed < 35)
        gasCost = gasUsed*0.3774;
    else
        gasCost = (35*0.3774) + (gasUsed-35)*0.34858;

    costBeforeTax = gasCost + 8.00;

//--------------------------------------------------------------------------------------
// LAST MONTH'S BILL
//--------------------------------------------------------------------------------------

	cout << "Was the last month's bill paid late? (Y/N)" << endl;
    do
    {
        cout << "Answer: ";
        cin >> yesNo;
        yesNo = toupper(yesNo);

        if (!cin || (yesNo != 'Y' && yesNo != 'N'))
        {
            cin.clear();
            cin.ignore(100, '\n');
            flag1 = false;
        }
        else
            flag1 = true;
    } while (!flag1);

    if (yesNo == 'Y')
    {
    	do
    	{
    		flag1 = true;
	    	cout << "Please enter the previous month's bill: ";
	        cin >> lateMonthBill;
	        if (!cin)
	        {
	        	cout << "Improper bill amount." << endl;
	        	cin.clear();
	        	cin.ignore(100, '\n');
	        	flag1 = false;
			}
		} while (!flag1);
        
		
//        costBeforeTax += lateMonthBill*0.015;
    }

//--------------------------------------------------------------------------------------
// DISPLAY
//--------------------------------------------------------------------------------------

    avgDailyCost = costBeforeTax/daysElapsed;
    totalCharges = costBeforeTax + 2.40 + lateMonthBill*0.015;

    cout << endl << endl
         << "Initial Date: " << initMonthName << ' ' << initDay << ", " << initYear << endl
         << "Final Date: " << finMonthName << ' ' << finDay << ", " << finYear << endl << endl;
        
		 
    cout << "Initial meter reading: " << initString << endl
    	 << "Final meter reading: ";
    
    if (finMeter-initMeter<0)
    	cout << 1;
    cout << finString << endl << endl
         << "Gas Used: " << gasUsed << " CCF" << endl
         << "Days in billing period: " << daysElapsed << endl;

    cout << fixed << setprecision(2);
    cout << "Gas cost: $" << gasCost << endl << endl;
    if (yesNo=='Y')
        cout << "Previous month's Bill: $" << lateMonthBill << endl
             << "Late charge: $" << lateMonthBill*0.015 << endl << endl;

    cout << "Utility tax: $2.40" << endl
         << "Cost before tax: $" << costBeforeTax << endl
         << "Total current charges: $" << totalCharges << endl
         << "Average daily cost: $" << avgDailyCost << endl;

    return 0;
}
