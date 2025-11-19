/*Given an array in the figure of integers, sort the array in ascending as well as descending order and
return it using radix sort
Steps of Radix Sort:
 Find the maximum number in the array to know the number of digits.
 Sort based on each digit, starting from the least significant digit (LSD) to the most significant
digit (MSD), using a stable sorting algorithm (such as counting sort).
 Repeat the sorting process for each digit position until all digits are processed.*/

#include <iostream>
using namespace std;

int values[10000];
int nextarr[10000];  
int freeidx=0;

int newNode(int v)
{
    values[freeidx] = v;
    nextarr[freeidx] = -1;
    return freeidx++;
}

void insertBucket(int& head, int& tail, int v)
{
    int node = newNode(v);
    if (head == -1)
    {
        head = node;
        tail = node;
    }
    else
    {
        nextarr[tail] = node;
        tail = node;
    }
}

void clearBucket(int& head, int& tail)
{
    head = -1;
    tail = -1;
}

int getMax(int arr[], int n)
{
    int m = arr[0];
    for (int i=1; i<n; i++)
    {
        if (arr[i] > m) 
        {
            m = arr[i];
        }
    }
    return m;
}

void radixSort(int arr[], int n)
{
    int maxNum = getMax(arr,n);
    int exp = 1;
    int head[10], tail[10];
    while (maxNum/exp > 0)
    {
        for (int i=0; i<10; i++)
        {
            head[i] = -1;
            tail[i] = -1;
        }

        for (int i=0; i<n; i++)
        {
            int digit = (arr[i]/exp) % 10;
            insertBucket(head[digit], tail[digit], arr[i]);
        }

        int idx=0;
        for (int i=0; i<10; i++)
        {
            int cur= head[i];
            while (cur != -1)
            {
                arr[idx++] = values[cur];
                cur = nextarr[cur];
            }
            clearBucket(head[i],tail[i]);
        }
        exp = exp * 10;
    }
}

void printasc(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printdesc(int arr[], int n)
{
    for (int i=n-1; i >= 0; i--)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {420,7,65,654,555,36,455,89,987,957,59,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr,n);
    cout << "Ascending Order: " << endl;
    printasc(arr,n);
    cout << "Descending Order: " << endl;
    printdesc(arr,n);
}