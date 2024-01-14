#include <iostream>
#include <stack>

using namespace std;

int findMaxLRProduct(int arr[], int N)
{
    int left_indices[N];
    int right_indices[N];
    stack<int> left_stack, right_stack;

    // Populate left_indices
    for (int i = 0; i < N; ++i)
    {
        if (left_stack.empty())
        {
            left_indices[i] = -1;
        }
        else
        {
            left_indices[i] = left_stack.top();
        }

        while (!left_stack.empty() && arr[left_stack.top()] <= arr[i])
        {
            left_stack.pop();
        }
        left_stack.push(i);
    }

    // Populate right_indices
    for (int i = N - 1; i >= 0; --i)
    {
        if (right_stack.empty())
        {
            right_indices[i] = -1;
        }
        else
        {
            right_indices[i] = right_stack.top();
        }

        while (!right_stack.empty() && arr[right_stack.top()] <= arr[i])
        {
            right_stack.pop();
        }
        right_stack.push(i);
    }

    int max_lr_product = 0;
    int max_lr_index = -1;

    // Calculate LRProduct(i) and find the maximum
    for (int i = 0; i < N; ++i)
    {
        int lr_product = (left_indices[i] + 1) * (right_indices[i] + 1);
        if (lr_product > max_lr_product)
        {
            max_lr_product = lr_product;
            max_lr_index = i;
        }
    }

    return max_lr_index;
}

int main()
{
    int arr[] = {4, 3, 5, 2, 1, 6};
    int N = sizeof(arr) / sizeof(arr[0]);
    int result_index = findMaxLRProduct(arr, N);
    cout << "Index with maximum LRProduct: " << result_index << endl;

    return 0;
}
