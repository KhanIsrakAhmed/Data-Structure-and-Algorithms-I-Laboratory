//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    15-07-2023     *************************\

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100; // Define a maximum value for N

int graph[MAX_N][MAX_N]; // Use the defined maximum value for array size

void dfs(int u, int N, int color[])
{
    cout << u << " "; // Print visited node
    color[u] = 1;     // Mark current node as visited

    for (int i = 0; i < N; i++)
    {
        if (graph[u][i] && color[i] == 0)
        {
            dfs(i, N, color); // Recursive call to unvisited neighbor
        }
    }
}

int main()
{
    int N;
    cout << "Enter the size of the array (N): ";
    cin >> N;

    // Input graph values
    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
        }
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    int color[MAX_N] = {0};   // Array to mark visited nodes
    dfs(startNode, N, color); // Start DFS from the specified node
    return 0;
}
