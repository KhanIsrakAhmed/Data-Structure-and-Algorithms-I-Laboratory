//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    01-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

int searchInRotatedSortedArray(int a[], int n, int k)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (a[mid] == k)
        {
            return mid;
        }

        if (a[left] <= a[mid])
        {
            if (k >= a[left] && k < a[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (k > a[mid] && k <= a[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return -1; // Element not found
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the target value: " << endl;
    int k;

    cin >> k;

    int index = searchInRotatedSortedArray(arr, n, k);

    if (index != -1)
    {
        cout << "Target element found at index: " << index << endl;
    }
    else
    {
        cout << "Target element not found." << endl;
    }

    return 0;
}
