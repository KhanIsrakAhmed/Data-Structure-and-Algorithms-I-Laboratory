//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    01-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

#include <iostream>
using namespace std;

int linear(int matrix[][3], int target)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (target == matrix[i][j])
            {
                return matrix[i][j];
            }
        }
    }
    return -1;
}

int main()
{
    int matrix[3][3] = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}};
    int target = 7;

    int x, y;
    int result = linear(matrix, target);

    if (result != -1)
    {
        cout << "Target found at position: " << x << ", " << y << endl;
    }
    else
    {
        cout << "Target not found in the matrix." << endl;
    }

    return 0;
}
