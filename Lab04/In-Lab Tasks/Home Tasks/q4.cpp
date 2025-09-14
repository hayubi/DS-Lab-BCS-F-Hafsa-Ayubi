/*4. Use Insertion Sort to sort an array of integers provided by the user. Then, implement the
Binary Search algorithm to find a target value within the newly sorted array. The program
should display the sorted array and the index of the found element or a message if it's not
present.*/

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

    //insertion sort
    for (int i=1; i<size; i++) 
    {
        int key = arr[i];
        int j = i-1;
        
        while (j >= 0 && arr[j] > key) 
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    cout << "Sorted array: ";
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //binary search
    int target;
    cout << "Enter target to search: ";
    cin >> target;
    int left=0, right = size-1, index=-1;
    while (left <= right) 
    {
        int mid = left + (right-left)/2;
        if (arr[mid] == target) 
        {
            index = mid;
            break;
        } 
        else if (arr[mid] < target) 
        {
            left = mid+1;
        } 
        else 
        {
            right = mid-1;
        }
    }

    if (index != -1)
        cout << "Target found at index: " << index << endl;
    else
        cout << "Target not found." << endl;

    delete[] arr;
}