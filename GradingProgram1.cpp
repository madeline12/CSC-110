// Madeline Navarro
// Grading Program (1)

#include <iostream>
#include <cctype>

using namespace std;

bool InvalidInput();
void GradeLetter(float);
char Repeat(char);

int main()
{
    float grade;
    char ans;

    do
        {
        do
            {
            cout << "Please enter the grade you scored: ";
            cin >> grade;
            cin.ignore(100, '\n');

            if (grade < 0 || grade > 100)
                cout << "Invalid grade." << endl;
            } while (!InvalidInput() || grade < 0 || grade > 100);

        GradeLetter(grade);
        cout << endl;
        } while (Repeat(ans) == 'Y');

    cout << "\nGoodbye!";

    return 0;
}

bool InvalidInput()
{
    if (!cin)
    {
        cout << "Invalid input." << endl;
        cin.clear();
        cin.ignore(100, '\n');
        return false;
    }
    else
        return true;
}


void GradeLetter(float g)
{
    if (g < 60)
            cout << "Your grade is an F.";
        else if (g < 70)
            cout << "Your grade is a D.";
        else if (g < 80)
            cout << "Your grade is a C.";
        else if (g < 90)
            cout << "Your grade is a B.";
        else
            cout << "Your grade is an A!";

}


char Repeat(char response)
{
    do
            {
            cout << "Would you like to enter another grade? (Y/N) =>";
            cin >> response;
            cin.ignore(100, '\n');
            response = toupper(response);
            } while (response != 'Y' && response != 'N');
    return response;
}
