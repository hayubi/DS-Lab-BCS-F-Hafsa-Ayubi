/*Task#3: Given an integer array arr[] of size n elements and a positive integer K, the
task is to return the kth largest element in the given array (not the Kth distinct
element).
Examples:
Input: [1, 23, 12, 9, 30, 2, 50], K = 3
Output: 23
Input: [12, 3, 5, 7, 19], K = 2
Output: 12
*/

#include <iostream>
using namespace std;

void heapifyDown(int arr[], int size, int i) 
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if (left<size && arr[left] > arr[largest])
        largest= left;
    if (right<size && arr[right] > arr[largest])
        largest = right;

    if (largest!=i) 
    {
        swap(arr[i],arr[largest]);
        heapifyDown(arr,size,largest);
    }
}

int kthLargest(int arr[], int size, int k) 
{
    for (int i = (size/2)-1; i>=0; i--)
        heapifyDown(arr,size,i);
    int heapSize = size;
    for (int i=1; i<k; i++) 
    {
        swap(arr[0],arr[heapSize-1]);
        heapSize--;
        heapifyDown(arr,heapSize,0);
    }
    return arr[0];
}

int main() 
{
    int arr1[] = {1,23,12,9,30,2, 50};
    int size1=7;
    int k1=3;
    cout << kthLargest(arr1,size1,k1) << endl;
    int arr2[] = {12,3,5,7,19};
    int size2=5;
    int k2=2;
    cout << kthLargest(arr2,size2,k2) << endl;
}
