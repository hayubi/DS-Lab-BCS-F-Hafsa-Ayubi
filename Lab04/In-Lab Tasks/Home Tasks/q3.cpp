/*3. Implement the Selection Sort algorithm. The program should take an array of integers from
the user, find the smallest element, and exchange it with the element at the first position.
This process should continue until the array is completely sorted. Display the sorted array
to the user.*/

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

    for (int i=0; i<size-1; i++)
    {
        int minIndex = i;
        for (int j=i+1; j<size; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "Sorted array: ";
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
}