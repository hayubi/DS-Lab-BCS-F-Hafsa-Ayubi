/*5. Implement the Interpolation Search algorithm. The program should take a sorted array
with uniformly distributed values and a target value from the user. The algorithm should
estimate the position of the target and check if the estimated position holds the correct
value. If the element is found, print its index; otherwise, indicate that it's not present.*/

#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int size, int x)
{
    int low=0;
    int high = size-1;
    while (low <= high && x >= arr[low] && x <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == x)
                return low;
            return -1;
        }

        int pos = low + ((x-arr[low]) * (high-low)) / (arr[high]-arr[low]);
        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x;
    cout << "Enter the value to search: ";
    cin >> x;

    int index = interpolationSearch(arr, size, x);
    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;
}