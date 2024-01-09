//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    05-07-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

using namespace std;

int maze[5][5] = {
    {0, 1, 2, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 3, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}};

int visited[5][5] = {0};

bool dfs(int row, int col, int sKey, stack<pair<int, int>> &row_col_stack)
{
    if (row < 0 || row > 4 || col < 0 || col > 4 || visited[row][col] == 1)
    {
        return false;
    }

    row_col_stack.push({row, col});
    visited[row][col] = 1;

    if (maze[row][col] == 2 && sKey == 2)
    {
        return true;
    }

    if (maze[row][col] == 3)
    {
        sKey = 2;
    }

    if (col + 1 <= 4 && maze[row][col + 1] != 1 && dfs(row, col + 1, sKey, row_col_stack))
    {
        return true;
    }
    if (row + 1 <= 4 && maze[row + 1][col] != 1 && dfs(row + 1, col, sKey, row_col_stack))
    {
        return true;
    }
    if (col - 1 >= 0 && maze[row][col - 1] != 1 && dfs(row, col - 1, sKey, row_col_stack))
    {
        return true;
    }
    if (row - 1 >= 0 && maze[row - 1][col] != 1 && dfs(row - 1, col, sKey, row_col_stack))
    {
        return true;
    }

    visited[row][col] = 0;
    row_col_stack.pop();
    return false;
}

int main()
{
    stack<pair<int, int>> row_col_stack;
    int row, col;
    cout << "Enter your starting point : ";
    cin >> row >> col;

    if (row < 0 || row > 4 || col < 0 || col > 4)
    {
        cout << "Invalid starting point." << endl;
        return 1;
    }

    if (dfs(row, col, 0, row_col_stack))
    {
        cout << "Path with treasure and exit:";
        while (!row_col_stack.empty())
        {
            cout << " (" << row_col_stack.top().first << "," << row_col_stack.top().second << ")<--";
            row_col_stack.pop();
        }
        cout << "Starting point(" << row << "," << col << ")";
        cout << endl;
    }
    else
    {
        cout << "No path with treasure found." << endl;
    }

    return 0;
}
