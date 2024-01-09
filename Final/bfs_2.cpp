//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    06-07-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100; // Define a maximum value for N

int graph[MAX_N][MAX_N]; // Use the defined maximum value for array size

void bfs(int start, int N)
{
    int color[MAX_N] = {0};
    color[start] = 1;

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < N; i++)
        {
            if (graph[u][i] && color[i] == 0)
            {
                q.push(i);
                color[i] = 1; // Mark neighbor as visited
            }
        }

        cout << u << " "; // Print visited node

        color[u] = 2; // Mark current node as visited
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

    bfs(startNode, N); // Start BFS from the specified node
    return 0;
}
