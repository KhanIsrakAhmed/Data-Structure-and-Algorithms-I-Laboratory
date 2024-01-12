//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    13-07-2023     *************************\

#include <bits/stdc++.h>
using namespace std;

int graph[5][5];

void dfs(int node, int color[])
{
    cout << node << " ";
    color[node] = 1;

    for (int i = 1; i < 5; i++)
    {
        if (graph[node][i] && color[i] == 0)
        {
            dfs(i, color);
        }
    }
}

void bfs(int start)
{
    int color[5] = {0};
    color[start] = 1;

    /*
    0 = White+-
    1 = Gray
    2 = Black
    */

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 1; i < 5; i++)
        {
            if (graph[u][i] && color[i] == 0)
            {
                q.push(i);
            }
        }
        color[u] = 1;
        cout << u << " ";
    }
}

int main()
{
    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            cin >> graph[i][j];
        }
    }
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << "DFS traversal: ";
    int dfs_color[5] = {0}; // Array to track visited nodes for DFS
    dfs(1, dfs_color);

    cout << "\nBFS traversal: ";
    bfs(1);

    return 0;
}
