//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    01-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

int findSmallestMissing(int a[], int n)
{

    int l = 0, h = n - 1;

    while (l < h)
    {
        int mid = (h + l) / 2;
        if (a[mid] > mid)
        {

            h = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int main()
{
    int n, product;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sm = findSmallestMissing(arr, n);

    cout << "Smallest Missing Number    : " << sm << endl;
    return 0;
}