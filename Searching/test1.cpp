//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    01-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter valus of k: " << endl;
    int k;

    cin >> k;

    for (int i = 0; i < n; i++)
    {
        if (k == arr[i])
        {
            sum = arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3];
        }
    }

    cout << "The valus of sum  " << sum << endl;
}