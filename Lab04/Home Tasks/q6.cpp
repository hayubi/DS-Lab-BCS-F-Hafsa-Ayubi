/*6. Implement the Comb Sort algorithm to sort an array of integers. This algorithm improves
upon bubble sort by reducing the number of comparisons and swaps using a "gap" that
decreases over time. After sorting, perform a complexity analysis: count and display the
total number of swaps and comparisons performed during the sorting process.*/

#include <iostream>
using namespace std;

void combSort(int arr[], int n)
{
    float shrink = 1.3f;
    int gap = n;
    bool swapped = true;
    int comparisons = 0;
    int swaps = 0;
    while (gap > 1 || swapped)
    {
        gap = (int)(gap/shrink);
        if (gap < 1)
        {
            gap = 1;
        }
        swapped = false;

        for (int i=0; i+gap < n; i++)
        {
            comparisons++;
            if (arr[i] > arr[i+gap])
            {
                int temp = arr[i];
                arr[i] = arr[i+gap];
                arr[i+gap] = temp;
                swaps++;
                swapped = true;
            }
        }
    }
    cout << "Total comparisons: " << comparisons << endl;
    cout << "Total swaps: " << swaps << endl;
}

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
    cout << "Original array: ";
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    combSort(arr, size);
    cout << "Sorted array: ";
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
