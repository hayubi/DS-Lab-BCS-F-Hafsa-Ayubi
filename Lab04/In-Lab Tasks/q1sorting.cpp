/*1. Implement the bubble sort algorithm to sort the in descending order (starting from the initial pass).
Take array [10] = (5,1,3,6,2,9,7,4,8,10%. You can also take your array as user input.*/

#include <iostream>
using namespace std;

int main() 
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int a[100];
    cout << "Enter " << size << " elements: ";
    for (int i=0; i<size; i++) 
    {
        cin >> a[i];
    }

    cout << "\nUnsorted array: ";
    for (int i=0; i<size; i++) 
    {
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i=0; i<size; i++) 
    {
        for (int j=0; j< size-1; j++) 
        {
            if (a[j] < a[j+1]) 
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    cout << "\nSorted array (descending): ";
    for (int i=0; i<size; i++) 
    {
        cout << a[i] << " ";
    }
    cout << endl;
}