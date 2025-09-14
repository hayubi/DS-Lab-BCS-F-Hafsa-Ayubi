/*2. Write a program to implement the Bubble Sort algorithm. The program should take
an array of integers as input from the user, sort the array using bubble sort, and then
display both the unsorted and sorted arrays.*/

#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Enter " << size << " values of array: " << endl;
    for (int i=0; i<size; i++)
    {
        cin >> arr[i];
    }

    cout << "\nUnsorted array: ";
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i=0; i<size; i++)
    {
        for (int j=0; j < size-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    cout << "Sorted array (ascending): ";
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
}