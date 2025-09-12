/*4. In a bustling corporate office, the facilities management team is tasked with organizing the seating arrangements for employees based on their designations. The office layout consists of rows of computer desks, and each desk has a designated employee. The priority is to sort out the computer desks for employees using the Insertion Sort algorithm, with the designation determining the sorting order. The higher the designation, the closer the employee should be seated to the corner office. The designations and their corresponding priorities are as follows:
i.CEO (Chief Executive Officer) - Highest Priority
il. СТО (Chief Technology Officer) 
iii. CFO (Chief Financial Officer) 
iv. VP (Vice President)
V. MGR (Manager)
vi. EMP (Employee) - Lowest Priority*/

#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int size;
    cout << "Enter number of employees: ";
    cin >> size;
    string *array = new string[size];
    cout << "Enter designations (CEO, CTO, CFO, VP, MGR, EMP):" << endl;
    for (int i=0; i<size; i++)
    {
        cin >> array[i];
    }
    cout << "\nUnsorted order: ";
    for (int i=0; i<size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    
    for (int i=1; i<size; i++) 
    {
        string key=array[i];
        int j = i-1, keyp;
        if (key == "CEO") 
            keyp = 6;
        else if (key == "CTO") 
            keyp = 5;
        else if (key == "CFO") 
            keyp = 4;
        else if (key == "VP")  
            keyp = 3;
        else if (key == "MGR") 
            keyp = 2;
        else if (key == "EMP") 
            keyp = 1;
        else 
            keyp = 0;

        while (j >= 0) 
        {
            int currp;
            if (array[j] == "CEO") 
                currp = 6;
            else if (array[j] == "CTO") 
                currp = 5;
            else if (array[j] == "CFO") 
                currp = 4;
            else if (array[j] == "VP")  
                currp = 3;
            else if (array[j] == "MGR") 
                currp = 2;
            else if (array[j] == "EMP") 
                currp = 1;
            else 
                currp = 0;

            if (currp< keyp) 
            {
                array[j+1] = array[j];
                j--;
            } 
            else
                break;
        }
        array[j+1]= key;
    }
    cout << "\nSorted: " << endl;
    for (int i=0; i<size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    delete[] array;
}