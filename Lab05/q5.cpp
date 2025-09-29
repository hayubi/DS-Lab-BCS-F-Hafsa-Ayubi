/*Task 5:
Implement a Sudoku solver using the backtracking technique. The program should take a
partially filled 9x9 Sudoku grid and fill the empty cells (represented by 0) to solve the puzzle.
Your algorithm should:
1. Find an empty cell.
2. Try placing a number from 1 to 9 in the empty cell.
3. Check if the number is valid in the current row, column, and 3x3 subgrid.
4. If valid, recursively call the function to solve the rest of the puzzle.
5. If the recursive call doesn't lead to a solution,
backtrack by resetting the cell to 0 and trying the next number.*/

#include <iostream>
using namespace std;

bool isSafe(int board[9][9], int row, int col, int digit)
{
    for (int j=0; j<9; j++) //horizontal
        if (board[row][j] == digit)
            return false;

    for (int i=0; i<9; i++) //vertical
        if (board[i][col] == digit)
            return false;

    //checking in each grid
    int startrow = (row/3)*3;
    int startcol = (col/3)*3;
    for (int i=startrow; i<startrow+3; i++) 
    {
        for (int j=startcol; j<startcol+3; j++)
        {
            if (board[i][j] == digit)
                return false;
        }
    }

    return true;
}

bool helper(int board[9][9], int row, int col)
{
    if (row == 9)
        return true;

    int nextrow = row;
    int nextcol = col+1;
    if (nextcol == 9)
    {
        nextrow = row+1;
        nextcol = 0;
    }

    if (board[row][col] != 0)
    {
        return helper(board, nextrow, nextcol);
    }

    //place digit
    for (int digit=1; digit<=9; digit++)
    {
        if (isSafe(board, row, col, digit))
        {
            board[row][col] = digit;
            if (helper(board, nextrow, nextcol))
            {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

// bool: to chk in main whether sudoku solved or not
bool sudoku(int board[9][9]) 
{
    if (!helper(board, 0, 0))
    {
        return false;
    }
    return true;
}

int main()
{
    int board[9][9] = 
    {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    bool ok1 = sudoku(board);

    if (ok1)
    {
        for (int i=0; i<9; i++)
        {
            for (int j=0; j<9; j++)
                cout << board[i][j] << " ";
            cout << endl; 
        }
    }
    else
        cout << "No solution" << endl;
}