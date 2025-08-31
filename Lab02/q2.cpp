/*Task #2:
Write a program that uses a dynamic 2D array to represent a seating chart in a classroom.
=> Rows represent benches, columns represent seats on each bench.
=> Initialize the array with 0 (empty).
=> Let the user fill seats (1 for occupied).
=> Print the final seating chart in matrix form.*/

#include <iostream>
using namespace std;

int main()
{
    int **arr;
    int rows, cols;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter columns: ";
    cin >> cols;

    arr = new int*[rows];
    for (int i=0; i<rows; i++)
    {
        arr[i] = new int[cols];
    }

    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            arr[i][j] = 0;
        }
    }

    cout << "Do you want to fill seats? ";
    char choice;
    cin >> choice;
    if (choice == 'y') 
    {
        cout << "How many seats do you want to fill? ";
        int size;
        cin >> size;
        if (size > (rows*cols))
        {
            cout << "Boundary error";
            return 0;
        }
        cout << "Enter the positions: " << endl;
        for (int i=0; i<size; i++)
        {
            cout << i+1 << ". ";
            int pos, r, c;
            cin >> pos;
            if (pos > (rows*cols))
            {
                cout << "Boundary error";
                return 0;
            }
            else
            {
                r = pos/cols;
                c = (pos%cols)-1;
                if(c==-1)
                {
                    c=cols;
                }
                arr[r][c] = 1;
            }
        }
    }

    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i=rows-1; i>=0; i--)
    {
        delete[] arr[i];
    }
    delete[] arr;
}