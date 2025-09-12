/*You've been given an array of numbers representing employee IDs. Your task is to identify the employee whose ID matches the last two digits of your roll number. If your roll number's last two digits are not present in the array, insert the missing value in its correct position within the array. You must use binary search to locate the position of that value within the array.*/

#include <iostream>
using namespace std;

int main() 
{
    int size;
    cout << "Enter number of employee IDs: ";
    cin >> size;
    int *array = new int[size];
    cout << "Enter " << size << " employee IDs: ";
    for (int i=0; i<size; i++)
    {
        cin >> array[i];
    }

    //sorting 
    for (int i=0; i < size-1; i++) 
    {
        for (int j=0; j < size-i-1; j++) 
        {
            if (array[j] > array[j+1]) 
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    int lastTwonums;
    cout << "Enter the last two digits of your roll number: ";
    cin >> lastTwonums;
    int left=0;
    int right=size;
    while (left < right) 
    {
        int mid = left+(right- left) / 2;

        if (array[mid] < lastTwonums)
            left= mid + 1;
        else
            right = mid;
    }
    int insertpos=left;

    if (insertpos<size && array[insertpos] == lastTwonums) 
    {
        cout << "Employee with ID " << lastTwonums << " found. Index: " << insertpos << endl;
    } 
    else 
    {
        int *newarr = new int[size+1];
        for (int i=0; i<insertpos; i++)
        {
            newarr[i] = array[i];
        }
        newarr[insertpos] = lastTwonums;

        //rest of the elements
        for (int i=insertpos; i<size; i++)
        {
            newarr[i+1] = array[i];
        }
        delete[] array;
        array = newarr;
        size++;

        cout << "ID " << lastTwonums << " not found. Inserted at index " << insertpos << endl;
        cout << "After insertion:";
        for (int i=0; i<size; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    delete[] array;
}
