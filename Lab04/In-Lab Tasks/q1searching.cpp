/*Write a C++ program to implement Linear Search. Your program should take an array of integers and a target value as input from the user. The program should search for the target value in the array using the linear search algorithm and output the index at which the target is found. If the target value is not found in the array, the program should display an appropriate message.*/

#include <iostream>
using namespace std;
int main() 
{
    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int *array = new int[size];
    cout << "Enter " << size << " integers: ";
    for (int i=0; i<size; i++) 
    {
        cin >> array[i];
    }

    int target;
    cout << "Enter the target value to search: ";
    cin >> target;
    int index = -1;
    for (int i=0; i<size; i++) 
    {
        if (array[i] == target) 
        { 
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Target value not found." << endl;
    }
    else
    {
        cout << "Target value found! Index: " << index << endl;
    }
    delete[] array;
}