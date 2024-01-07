//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    01-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

int findSame(int a[], int n, int k)
{
    int low = 0, high = n - 1;
    int cnt = 0;

    while (low < high)
    {
        int mid = (high + low) / 2;

        if (a[mid] == k)
        {
            cnt++;
            int left = mid - 1;
            while (left >= 0 && a[left] == k)
            {
                cnt++;
                left--;
            }
            int right = mid + 1;
            while (right < n && a[right] == k)
            {
                cnt++;
                right++;
            }
            break;
        }
        else if (a[mid] < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return cnt;
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

    int sm = findSame(arr, n, k);
    cout << "Number of repetitions of " << k << ": " << sm << endl;

    return 0;
}
