/*Task 7:
Create a program that solves the N-Queens problem for any given N using backtracking. The
program should print all possible solutions for placing N queens on an N x N chessboard so
that no two queens threaten each other. This task requires you to use a recursive function to
place queens row by row , and a validation function to check if a queen can be placed in a
specific cell. If a placement leads to a conflict, the algorithm should backtrack to the previous
row and try a different column.*/

#include <iostream>
using namespace std;

bool isSafe(int **board, int row, int col, int n)
{
    for (int i=0; i<row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    for (int i=row, j=col; i>=0 && j>=0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }
        
    for (int i=row, j=col; i>=0 && j<n; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool nQueens(int **board, int row, int n)
{
    if (row >= n)
        return true;

    for (int i=0; i<n; i++)
    {
        if (isSafe(board, row, i, n))
        {
            board[row][i] = 1;
            if (nQueens(board, row+1, n))
            {
                return true;
            }
            board[row][i] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    int **board = new int *[n];
    for (int i=0; i<n; i++)
    {
        board[i] = new int[n]{0};
    }

    if (nQueens(board, 0, n))
    {
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "No solution for n: " << n << endl;

    for (int i=0; i<n; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}
