/*Task#2: Look at above tree and write a function to check if a given array represents
a Binary Heap? Also that sort the array in ascending order.*/

#include <iostream>
using namespace std;

bool isHeap (int arr[], int n) 
{
    for (int i=0; i <= (n-2)/2; i++) 
    {
        int left  = 2*i+1;
        int right = 2*i+2;

        if (left < n && arr[i] < arr[left])
            return false;

        if (right < n && arr[i] < arr[right])
            return false;
    }
    return true;
}

void heapify (int arr[], int n, int i) 
{
    int largest = i;
    int left  = 2*i+1;
    int right = 2*i+2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) 
    {
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapSort (int arr[], int n) 
{
    for (int i = n/2-1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n-1; i>0; i--) 
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() 
{
    int arr[] = {20,18,10,12,9,9,3,5,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    if (isHeap(arr,n))
        cout << "Array represents a max binary heap\n";
    else
        cout << "Array does NOT represent a max binary heap\n";
    heapSort(arr,n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}