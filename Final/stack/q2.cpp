#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int maze[5][5] = {
    {0, 1, 2, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 3, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}};

int visited[5][5] = {0};

bool dfs(int row, int col, int sKey, stack<pair<int, int>> &row_col_stack, vector<pair<int, int>> &shortest_path)
{
    if (row < 0 || row > 4 || col < 0 || col > 4 || visited[row][col] == 1)
    {
        return false;
    }

    row_col_stack.push({row, col});
    visited[row][col] = 1;

    if (maze[row][col] == 2 && sKey == 2)
    {
        shortest_path.clear();
        while (!row_col_stack.empty())
        {
            shortest_path.push_back(row_col_stack.top());
            row_col_stack.pop();
        }
        return true;
    }

    if (maze[row][col] == 3)
    {
        sKey = 2;
    }

    if (maze[row][col + 1] != 1 && dfs(row, col + 1, sKey, row_col_stack, shortest_path))
    {
        return true;
    }
    if (maze[row + 1][col] != 1 && dfs(row + 1, col, sKey, row_col_stack, shortest_path))
    {
        return true;
    }
    if (maze[row][col - 1] != 1 && dfs(row, col - 1, sKey, row_col_stack, shortest_path))
    {
        return true;
    }
    if (maze[row - 1][col] != 1 && dfs(row - 1, col, sKey, row_col_stack, shortest_path))
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
    vector<pair<int, int>> shortest_path;
    int row, col;
    cout << "Enter your starting point : ";
    cin >> row >> col;
    if (dfs(row, col, 0, row_col_stack, shortest_path))
    {
        cout << "Path with treasure and exit:";
        stack<pair<int, int>> temp_stack = row_col_stack;
        while (!temp_stack.empty())
        {
            cout << " (" << temp_stack.top().first << "," << temp_stack.top().second << ")<--";
            temp_stack.pop();
        }
        cout << endl;

        cout << "Shortest path with treasure and exit:";
        for (auto it = shortest_path.rbegin(); it != shortest_path.rend(); ++it)
        {
            cout << " (" << it->first << "," << it->second << ")<--";
        }
        cout << "Starting point(" << row << ", " << col << ")";

        cout << endl;
    }
    else
    {
        cout << "No path with treasure found." << endl;
    }

    return 0;
}
