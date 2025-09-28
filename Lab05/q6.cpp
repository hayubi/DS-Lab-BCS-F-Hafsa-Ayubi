/*Task 6:
Modify the provided "Rat in a Maze" code to handle a more complex version of the problem.
The rat should now be able to move in four directions (up, down, left, and right) instead of just
two. Your updated code should still use backtracking to find a valid path from the source (0,0) to
the destination (N-1, N-1) while avoiding dead ends.*/

#include <iostream>
using namespace std;
#define n 5

void printsol(int sol[n][n])
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int maze[n][n], int x, int y, int visited[n][n])
{
    if (x >= 0 && x<n &&
            y >= 0 && y<n &&
            maze[x][y] == 1 &&
            visited[x][y] == 0)
    {
        return true;
    }
    return false;
}

bool searchpath(int maze[n][n], int x, int y, int sol[n][n], int visited[n][n])
{
    if (x == n-1 && y == n-1)
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, visited))
    {
        sol[x][y] = 1;
        visited[x][y] = 1;

        if (searchpath(maze, x, y+1, sol, visited)) // right
            return true;
        if (searchpath(maze, x+1, y, sol, visited)) // down
            return true;
        if (searchpath(maze, x, y-1, sol, visited)) // left
            return true;
        if (searchpath(maze, x-1, y, sol, visited)) // up
            return true;

        sol[x][y] = 0;
        visited[x][y] = 0;
        return false;
    }
    return false;
}

void solveMaze(int maze[n][n])
{
    int sol[n][n] = {0};
    int visited[n][n] = {0};

    if (!searchpath(maze, 0, 0, sol, visited))
    {
        cout << "No solution" << endl;
        return;
    }
    printsol(sol);
}

int main()
{
    int maze[n][n] = 
    {
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1}
    };
    solveMaze(maze);
}
