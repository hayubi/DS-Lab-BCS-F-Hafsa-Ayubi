/*Question#5: For the following graph implement the following:
 Create an Adjacency List and Adjacency Matrix. Display the list and matrix.
 Traverse the graph using BFS and DFS.
 Display the output for both the traversals.*/

#include <iostream>
using namespace std;

#define MAX 20

int adjList[MAX][MAX];
int listSize[MAX];
int adjMatrix[MAX][MAX];
bool visited[MAX];

void DFS(int u, int n) 
{
    cout << u << " ";
    visited[u] = true;

    for (int i=0; i < listSize[u]; i++) 
    {
        int v = adjList[u][i];
        if (!visited[v])
        {
            DFS(v,n);
        }
    }
}

void BFS(int start, int n) 
{
    bool seen[MAX] = {false};
    int q[MAX];
    int front=0;
    int rear=0;

    q[rear++] = start;
    seen[start] = true;

    while (front < rear) 
    {
        int u = q[front++];
        cout << u << " ";
        for (int i=0; i < listSize[u]; i++) 
        {
            int v = adjList[u][i];
            if (!seen[v]) 
            {
                seen[v] = true;
                q[rear++] = v;
            }
        }
    }
}

int main() 
{
    int n,e;
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    for (int i=0; i<n; i++) 
    {
        listSize[i] = 0;
        for (int j=0; j<n; j++)
            adjMatrix[i][j] = 0;
    }

    cout << "Enter edges (u v):\n";
    for (int i=0; i < e; i++) 
    {
        int u,v;
        cin >> u >> v;
        adjList[u][listSize[u]++] = v;
        adjList[v][listSize[v]++] = u;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    cout << endl << "Adjacency List:" << endl;
    for (int i=0; i<n; i++) 
    {
        cout << i << " -> ";
        for (int j=0; j < listSize[i]; j++)
            cout << adjList[i][j] << " ";
        cout << endl;
    }

    cout << endl << "Adjacency Matrix:" << endl; 
    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<n; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }

    cout << endl << "DFS Traversal";
    for (int i=0; i<n; i++)
        visited[i] = false;
    DFS(0,n);

    cout << endl << "BFS Traversal";
    BFS(0,n);
}