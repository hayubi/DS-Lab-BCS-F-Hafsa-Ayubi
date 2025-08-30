/*Task #9:
Implement a program to represent a sparse matrix using a dynamic 2D array.
=> Input matrix elements.
=> Display the matrix in normal form.
=> Display the matrix in compressed form (row, column, value).*/

#include <iostream>
using namespace std;

int main()
{
    int **matrix, **newmatrix;
    int rows, cols;
    cout << "Enter rows: ";
    cin >> rows;
    cout << "Enter columns: ";
    cin >> cols;
    matrix = new int*[rows];
    for (int i=0; i<rows; i++)
    {
        matrix[i] = new int[cols];
    }

    cout << "Enter values: " << endl;
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Matrix in normal form: " << endl;
    for (int i=0; i<rows; i++)
    {
        cout << "[ ";
        for (int j=0; j<cols; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;

    int count = 0;
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                count++;
            }
        }
    }
    newmatrix = new int*[count];
    for (int i=0; i<count; i++)
        newmatrix[i] = new int[3];

    int k = 0; //necessary bcz then multiple non zero values in 1 row will be skipped
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                newmatrix[k][0] = i+1;
                newmatrix[k][1] = j+1;
                newmatrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    cout << "Matrix in compressed form: " << endl;
    cout << "Row " << "Column  " << "Value" << endl;
    for (int i=0; i<count; i++)
    {
        cout << newmatrix[i][0] << "     "
            << newmatrix[i][1] << "       "
            << newmatrix[i][2] << endl;
    }


    for (int i=0; i<rows; i++)
        delete[] matrix[i];
    delete[] matrix;

    for (int i=0; i<count; i++)
        delete[] newmatrix[i];
    delete[] newmatrix;
}
