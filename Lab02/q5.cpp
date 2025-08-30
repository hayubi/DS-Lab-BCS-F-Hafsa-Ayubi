/*Task #5:
Write a C++ program that dynamically creates a 2D matrix and provides:
=> Addition of two matrices.
=> Subtraction of two matrices.
=> Ensure safe memory handling with proper allocation/deallocation.*/

#include <iostream>
using namespace std;

int main()
{
    int **matrix1, **matrix2;
    int rows1, cols1, rows2, cols2;
    cout << "Matrix 1: " << endl << "Rows: ";
    cin >> rows1;
    cout << "Columns: ";
    cin >> cols1;
    matrix1 = new int*[rows1];
    for (int i=0; i<rows1; i++)
    {
        matrix1[i] = new int[cols1];
    }
    cout << "Enter values of matrix 1: " << endl;
    for (int i=0; i<rows1; i++)
    {
        for (int j=0; j<cols1; j++)
        {
            cin >> matrix1[i][j];
        }
    }

    cout << "Matrix 2: " << endl << "Rows: ";
    cin >> rows2;
    cout << "Columns: ";
    cin >> cols2;
    matrix2 = new int*[rows2];
    for (int i=0; i<rows2; i++)
    {
        matrix2[i] = new int[cols2];
    }
    cout << "Enter values of matrix 1: " << endl;
    for (int i=0; i<rows2; i++)
    {
        for (int j=0; j<cols2; j++)
        {
            cin >> matrix2[i][j];
        }
    }

    cout << "Matrix 1: " << endl;
    for (int i=0; i<rows1; i++)
    {
        cout << "[ ";
        for (int j=0; j<cols1; j++)
        {
            cout << matrix1[i][j] << " ";
        }
        cout << "]" << endl;
    } cout << endl;
    cout << "Matrix 2: " << endl;
    for (int i=0; i<rows2; i++)
    {
        cout << "[ ";
        for (int j=0; j<cols2; j++)
        {
            cout << matrix2[i][j] << " ";
        }
        cout << "]" << endl;
    }

    char choice;
    cout << endl << "What do you want to perform? " << "1. Addition | 2. Subtraction" << endl;
    cin >> choice;
    if (rows1 != rows2 || cols1 != cols2)
    {
        cout << "Cannot perform operation. Matrices must have same number of rows and columns." << endl;
        for (int i=0; i<rows1; i++)
        {
            delete[] matrix1[i];
        }
        delete[] matrix1;
        for (int i=0; i<rows2; i++)
        {
            delete[] matrix2[i];
        }
        delete[] matrix2;
        return 0;
    }
    else
    {
        int **resultant = new int*[rows1];
        for (int i=0; i<rows1; i++)
        {
            resultant[i] = new int[cols1];
        }

        for (int i=0; i<rows1; i++)
        {
            for (int j=0; j<cols1; j++)
            {
                if (choice == '1')
                    resultant[i][j] = matrix1[i][j] + matrix2[i][j];
                else if (choice == '2')
                    resultant[i][j] = matrix1[i][j] - matrix2[i][j];
                else 
                {
                    for (int k=0; k<rows1; k++)
                    {
                        delete[] resultant[k];
                    }
                    delete[] resultant;
                    for (int k=0; k<rows1; k++)
                    {
                        delete[] matrix1[k];
                    }
                    delete[] matrix1;
                    for (int k=0; k<rows2; k++)
                    {
                        delete[] matrix2[k];
                    }
                    delete[] matrix2;
                    return 0;
                }
            }
        }

        cout << endl << "Resultant Matrix: " << endl;
        for (int i=0; i<rows1; i++)
        {
            cout << "[ ";
            for (int j=0; j<cols1; j++)
            {
                cout << resultant[i][j] << " ";
            }
            cout << "]" << endl;
        } cout << endl;

        for (int i=0; i<rows1; i++)
        {
            delete[] resultant[i];
        }
        delete[] resultant;
    }

    for (int i=0; i<rows1; i++)
    {
        delete[] matrix1[i];
    }
    delete[] matrix1;
    for (int i=0; i<rows2; i++)
    {
        delete[] matrix2[i];
    }
    delete[] matrix2;
}