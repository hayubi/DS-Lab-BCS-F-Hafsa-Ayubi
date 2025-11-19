/*Task-3: Suppose you are working for a company that organizes a marathon every year. There are 10
participants in the marathon, and their finish times are recorded in seconds.

Write a program in C++ that uses Merge sort to find the top 5 fastest runners. Create an array of
runner objects that will store the participant's name and finish time in seconds.
 Prompt the user to input the participant&#39;s names and finish times into the array.
 Implement a merge function that will merge two subarrays of runners based on their finish
time in ascending order.
 Use the Merge sort algorithm to sort the runners based on their finish time by calling the
merge function in step 3.
 Display the top 5 fastest runners to the console, along with their name and finish time in
seconds.
 Use the appropriate data types and size for the arrays and variables to ensure efficient
memory usage.

Steps of Merge Sort:
 Divide: Split the array into two halves until each sub-array contains a single element.
 Conquer (Sort): Recursively sort each half.
 Merge: Merge the two sorted halves into a single sorted array.*/

#include <iostream>
#include <string>
using namespace std;

class Runner
{
    public:
        string name;
        int time;
};

void merge(Runner arr[], int left, int mid, int right) // merge 2 sorted halves
{
    int an = mid-left+1;   // size of left subarray
    int bn = right-mid;      // size of right subarray

    Runner a[an];
    Runner b[bn];

    for (int i=0; i<an; i++)
        a[i] = arr[left+i];

    for (int j=0; j<bn; j++)
        b[j] = arr[mid+1+j];

    int i=0, j=0, k=left;
    while (i<an && j<bn)
    {
        if (a[i].time <= b[j].time)
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }

    while (i<an)
        arr[k++] = a[i++];
    while (j<bn)
        arr[k++] = b[j++];
}

void mergeSort(Runner arr[], int left, int right)
{
    if (left >= right)
        return;
    int mid = left+(right-left)/2;
    mergeSort(arr,left,mid);
    mergeSort(arr,mid+1,right);
    merge(arr,left,mid,right);
}

int main()
{
    const int N=10;
    Runner runners[N];
    for (int i=0; i<N; i++)
    {
        cout << "Enter name and finish time for runner " << i+1 << ": ";
        cin >> runners[i].name >> runners[i].time;
    }
    mergeSort(runners, 0, N-1);
    cout << endl << "Top 5 fastest runners:" << endl;
    for (int i=0; i<5; i++)
        cout << runners[i].name << " " << runners[i].time << " seconds" << endl;
}