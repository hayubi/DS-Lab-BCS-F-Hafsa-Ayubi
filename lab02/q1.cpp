/*Task #1:
Implement a program that dynamically allocates a 1D array of integers.
=> The size should be given by the user.
=> Initialize all elements with zero.
=> Then, let the user update values at different positions.
=> Finally, print the array and deallocate memory properly.*/

#include <iostream>
using namespace std;

int main()
{
    int *arr;
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    arr = new int[size];
    for (int i=0; i<size; i++)
    {
        arr[i] = 0;
    }

    char choice;
    do 
    {
        cout << "Do you want to update any position? ";
        cin >> choice;
        if (choice == 'y')
        {
            cout << "Enter the position you want to update: ";
            int pos, value;
            cin >> pos;
            cout << "Enter the value: ";
            cin >> value;
            arr[pos-1] = value;
        }
    } while (choice != 'n');
    
    for (int i=0; i<size; i++)
    {
        cout << "Position: " << i+1 << " | Value: " << arr[i] << endl; 
    }
    
    for (int i=size; i>0; i--)
    {
        delete[] arr;
    }
}