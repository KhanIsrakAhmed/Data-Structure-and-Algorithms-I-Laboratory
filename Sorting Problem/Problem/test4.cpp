//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    17-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

/* Maximum & minimum difference element in a sorted array */

void insertion(int arr[], int n)
{
    for (int i = 1; i < n; i++) // START WITH INDEX 1
    {
        int key = arr[i];
        int j = i - 1; // 0 index

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // index 1 = index 0
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

void maxcdiff(int arr[], int n)
{
    int maxDiff = arr[1] - arr[0];
    for (int i = 2; i < n; i++)
    {
        int diff = arr[i] - arr[i - 1];
        if (diff > maxDiff)
        {
            maxDiff = diff;
        }
    }
    cout << "Pair with largest difference: " << maxDiff << endl;
}

void mindiff(int arr[], int n)
{
    int minDiff = arr[1] - arr[0];
    for (int i = 2; i < n; i++)
    {
        int diff = arr[i] - arr[i - 1];
        if (diff < minDiff)
        {
            minDiff = diff;
        }
    }
    cout << "Pair with smallest difference: " << minDiff << endl;
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Original Array" << endl;
    print(arr, n);

    cout << "Array after Sorting" << endl;
    insertion(arr, n);
    print(arr, n);

    maxcdiff(arr, n);
    mindiff(arr, n);

    return 0;
}
