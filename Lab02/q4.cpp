/*Task #4:
Create a dynamic program that manages monthly expenses for a family.
=> Use a 1D dynamic array to store expenses for n months.
=> Add a feature to resize the array if the user wants to track more months later.
=> Compute and display the total and average expenses.*/

#include <iostream>
using namespace std;

int main()
{
    int numofmonths;
    cout << "Enter number of months: ";
    cin >> numofmonths;
    double *expenses = new double[numofmonths];

    double sum = 0.0, avg = 0.0;
    cout << "Enter expenses for " << numofmonths << " months: " << endl;
    for (int i=0; i<numofmonths; i++)
    {
        cout << "month " << i+1 << ": ";
        cin >> expenses[i];
        sum = sum + expenses[i];
    }

    cout << "Do you want to resize the array (y/n)? ";
    char choice;
    cin >> choice;
    if (choice == 'y')
    {
        cout << "Enter number of months you want to add: ";
        int newmonths;
        cin >> newmonths;
        expenses = new double[numofmonths + newmonths];
        cout << "Enter expenses for " << newmonths << " new months: " << endl;
        for (int i=0; i<newmonths; i++)
        {
            cout << "month " << numofmonths+i+1 << ": ";
            cin >> expenses[i];
            sum = sum + expenses[i];
        }
        avg = sum/(numofmonths + newmonths);
    }
    else
        avg = sum/numofmonths;

    cout << "Total: $" << sum << endl;
    cout << "Average: $" << avg << endl;

    delete[] expenses;
}