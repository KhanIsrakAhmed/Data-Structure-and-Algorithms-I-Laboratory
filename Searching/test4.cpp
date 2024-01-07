//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    01-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int k)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the elements of the array:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int index = binarySearch(arr, n, k);

    if (index != -1)
    {
        cout << "Element found at index: " << index << endl;
    }
    else
    {
    }

    return 0;
}
