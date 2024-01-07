//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    01-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

int findFirstOccurrence(int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;
    int firstOccurrence = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            firstOccurrence = mid;
            right = mid - 1;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return firstOccurrence;
}

int main()
{
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int firstIndex = findFirstOccurrence(arr, n, k);

    if (firstIndex != -1)
    {
        cout << "First occurrence of target element found at index: " << firstIndex << endl;
    }
    else
    {
        cout << "Target element not found." << endl;
    }

    return 0;
}
