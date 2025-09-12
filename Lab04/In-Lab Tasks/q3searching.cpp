/*Your team has been given a large dataset (input by user) of sorted, uniformly distributed account balances. If the data is not sorted, you have to sort it first. If the data is not uniformly distributed after you apply sorting (if necessary) you can prompt an error. Your manager has asked you to implement Interpolation Search because it estimates the position of the target value based on the data distribution. This will allow the search to "jump" closer to the target in fewer iterations.*/

#include <iostream>
using namespace std;

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    int* array = new int[size];
    cout << "Enter " << size << " balances: ";
    for (int i=0; i<size; i++)
    {
        cin >> array[i];
    }

    bool sorted = true;
    for (int i=1; i<size; i++)
    {
        if (array[i] < array[i-1])
        {
            sorted = false;
            break;
        }
    }

    //sorting
    if (!sorted)
    {
        for (int i=0; i < size-1; i++)
        {
            bool swapped = false;
            for (int j=0; j < size-i-1; j++)
            {
                if (array[j] > array[j+1])
                {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                    swapped = true;
                }
            }
            if (!swapped) 
                break;
        }
    }

    //uniform distribution
    bool uniform=true;
    if (size >= 2)
    {
        int gap = array[1]-array[0];
        if (gap <= 0) uniform = false;
        else
        {
            for (int i=2; i<size; i++)
            {
                if (array[i] - array[i-1] != gap)
                {
                    uniform=false;
                    break;
                }
            }
        }
    }
    if (!uniform)
    {
        cout << "Error" << endl;
        delete[] array;
        return 0;
    }

    int target;
    cout << "Enter the balance to search: ";
    cin >> target;
    int low=0;
    int high =size-1;
    int index=-1;
    while (low <= high && target >= array[low] && target <= array[high])
    {
        if (array[low] == array[high])
        {
            if (array[low] == target) index = low;
            break;
        }
        int pos = low + ((target - array[low]) * (high - low))/(array[high] - array[low]);

        if (array[pos] == target)
        {
            index =pos;
            break;
        }
        else if (array[pos] < target)
            low = pos+1;
        else
            high = pos-1;
    }

    if (index != -1)
        cout << "Taregt found. Index " << index << endl;
    else
        cout << "Target not found" << endl;
    delete[] array;
}