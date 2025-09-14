/*7. Implement the Shell Sort algorithm to sort an array of integers. The algorithm should start
with a large gap, then perform a gapped insertion sort, and gradually reduce the gap until
it's 1. After sorting, compare its performance against the Bubble Sort and Insertion Sort
algorithms for the same input array size (e.g., 1000 elements). Record and display the time
taken and the number of comparisons/swaps for all three algorithms to demonstrate why
Shell Sort is an improvement over Insertion Sort.*/

#include <iostream>
#include <ctime>
using namespace std;

void shellSort(int myarr[], int n1, int &cmp, int &swp)
{
    for (int gap = n1/2; gap>0; gap /= 2)
    {
        for (int j=gap; j<n1; j++)
        {
            int temp = myarr[j];
            int res = j;

            while (res >= gap && (++cmp && myarr[res-gap] > temp))
            {
                myarr[res] = myarr[res-gap];
                res = res - gap;
                swp++;
            }
            myarr[res] = temp;
        }
    }
}

void bubbleSort(int arr[], int size, int &cmp, int &swp)
{
    for (int i=0; i<size; i++)
    {
        for (int j=0; j < size-1-i; j++)
        {
            cmp++;
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swp++;
            }
        }
    }
}

void insertionSort(int arr[], int size, int &cmp, int &swp)
{
    for (int i=1; i<size; i++)
    {
        int key = arr[i];
        int j = i-1;

        while (j >= 0 && (++cmp && arr[j] > key))
        {
            arr[j+1] = arr[j];
            j--;
            swp++;
        }
        arr[j+1] = key;
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int *base = new int[n];
    cout << "Enter " << n << " integers: ";
    for (int i=0; i<n; i++)
    {
        cin >> base[i];
    }
    int *a1 = new int[n]; 
    int *a2 = new int[n]; 
    int *a3 = new int[n];
    for (int i=0; i<n; i++)
    {
        a1[i] = a2[i] = a3[i] = base[i];
    }

    int cmpShell=0, cmpBubble=0, cmpInsertion=0;
    int swpShell=0, swpBubble=0, swpInsertion=0;
    clock_t t1 = clock();
    shellSort(a1, n, cmpShell, swpShell);
    t1 = clock() - t1;
    clock_t t2 = clock();
    bubbleSort(a2, n, cmpBubble, swpBubble);
    t2 = clock() - t2;
    clock_t t3 = clock();
    insertionSort(a3, n, cmpInsertion, swpInsertion);
    t3 = clock() - t3;
    cout << "Performance Comparison: " << endl;
    cout << "Shell Sort:    time = " << ((double)t1/CLOCKS_PER_SEC) << " s, comparisons = " << cmpShell << ", swaps = " << swpShell << endl;
    cout << "Bubble Sort:   time = " << ((double)t2/CLOCKS_PER_SEC) << " s, comparisons = " << cmpBubble << ", swaps = " << swpBubble << endl;
    cout << "Insertion Sort: time = " << ((double)t3/CLOCKS_PER_SEC) << " s, comparisons = " << cmpInsertion << ", swaps = " << swpInsertion << endl;

    delete[] base; 
    delete[] a1; 
    delete[] a2;
    delete[] a3;
}