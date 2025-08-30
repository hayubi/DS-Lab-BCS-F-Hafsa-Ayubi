/*Task #8:
Create a dynamic program to store temperature readings of a city for n days and m different times in a day
using a 2D array.
=> Calculate the daily average temperature.
=> Find the hottest and coldest day.*/

#include <iostream>
using namespace std;

int main()
{
    int ndays, mtimes;
    cout << "Enter number of days: ";
    cin >> ndays;
    cout << "Enter numer of times in a day: ";
    cin >> mtimes;
    int **readings = new int*[ndays];
    for(int i=0; i<ndays; i++)
    {
        readings[i] = new int[mtimes];
    }

    for (int i=0; i<ndays; i++)
    {
        cout << "Enter Readings for day " << i+1 << ": " << endl;
        for (int j=0; j<mtimes; j++)
        {
            cout << "Time " << j+1 << ": "; 
            cin >> readings[i][j];
        }
    }

    int sum = 0;
    for (int j=0; j<mtimes; j++)
    {
        sum = sum + readings[0][j]; //for day1 only
    }
    float avgd1 = static_cast<float>(sum)/mtimes;

    float hottest = avgd1, coldest = avgd1; //assuming day1 is hottest and coldest
    int hday = 0, cday = 0;
    cout << "Average Temperature for Day 1: " << avgd1 << endl << endl;
    for (int i=1; i<ndays; i++)
    {
        sum = 0;
        for (int j=0; j<mtimes; j++)
        {
            sum += readings[i][j];
        }
        float avg = static_cast<float>(sum)/mtimes;

        if (avg > hottest)
        {
            hottest = avg;
            hday = i;
        }
        if (avg < coldest)
        {
            coldest = avg;
            cday = i;
        }
        cout << endl << "Average Temperature for Day " << i+1 << ": " << avg << endl;
    }
    cout << "Hottest Day: " << hday+1 << endl;
    cout << "Coldest Day: " << cday+1 << endl;

    for (int i=0; i<ndays; i++)
    {
        delete[] readings[i];
    }
    delete[] readings;
}