/*1. Implement a linear search algorithm to find a specific integer in an array. The program
should take an array of integers and a target value as input from the user. Print the index of
the target value if it's found or a message indicating that the element is not in the array.*/

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

    int target;
    cout << "Enter the value to search: ";
    cin >> target;
    int index = -1;
    for (int i=0; i<size; i++) 
    {
        if (arr[i] == target) 
        { 
            index = i;
            break;
        }
    }
    if (index == -1)
        cout << "Target value not found" << endl;
    else
        cout << "Target value found at index: " << index << endl;

    delete[] arr;
}