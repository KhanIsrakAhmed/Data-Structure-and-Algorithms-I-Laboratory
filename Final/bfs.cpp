#include <bits/stdc++.h>
using namespace std;
#define size 4

int graph[size][size] = {{0, 1, 1, 0}, {1, 0, 0, 0}, {1, 0, 0, 1}, {0, 0, 1, 0}};

/*
0 = White+-
1 = Gray
2 = Black

*/

void bfs(int start)
{
    int color[4] = {0};
    color[start] = 1;

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < size; i++)
        {
            if (graph[u][i] == 1 && color[i] == 0)
            {
                q.push(i);
            }
        }

        color[u] = 2;
        cout << u << " " << endl;
    }
}

int main()
{
    /*for (int i= 0; i < size; i++)
    {
        for (int j = 0; i < size; j++)
        {
            cout<< graph[i][j] << endl;
        }

    }*/

    bfs(2);

    return 0;
}
