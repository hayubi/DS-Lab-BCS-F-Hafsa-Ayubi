/*Task #7:
A company has multiple departments, each department has a different number of employees.
=> Use a jagged array where each row corresponds to a department and columns store employee
salaries.
Calculate:
-> The highest salary in each department.
-> The department with the overall maximum average salary.*/

#include <iostream>
using namespace std;

int main()
{
    int numdeps, maxavgdep;
    cout << "Enter number of departments: ";
    cin >> numdeps;
    int *highestsalaries = new int[numdeps];
    int **departments = new int*[numdeps];
    int *salaries = new int[numdeps];

    float globalMaxAvg = -1;

    cout << "Enter number of employees for: " << endl;
    for (int i=0; i<numdeps; i++)
    {
        int numemployees, highestsal=0, maxavg=0;
        cout << "\nDepartment " << i+1 << ": ";
        cin >> numemployees;
        salaries[i] = numemployees;
        departments[i] = new int[numemployees];

        cout << "Enter salary for " << numemployees << " employees: " << endl;
        int sum=0;
        for(int j=0; j<numemployees; j++)
        {
            cout << "employee " << j+1 << ". ";
            cin >> departments[i][j];
            sum = sum + departments[i][j];
            if (departments[i][j] > highestsal)
            {
                highestsal = departments[i][j];
            }
            highestsalaries[i] = highestsal;
            float avg = static_cast<float>(sum)/numemployees;
            if (avg > globalMaxAvg)
            {
                globalMaxAvg = avg;
                maxavgdep = i;
            }
        }
    }
    cout << "Highest salaries in each department: " << endl;
    for (int i=0; i<numdeps; i++)
    {
        cout << "Dep 1: " << highestsalaries[i] << endl; 
    }
    cout << "Maximum Average Salary Department: " << maxavgdep+1 << endl;

    for (int i=0; i<numdeps; i++)
    {
        delete[] departments[i];
    }
    delete[] departments;
    delete[] salaries;
    delete[] highestsalaries;
}