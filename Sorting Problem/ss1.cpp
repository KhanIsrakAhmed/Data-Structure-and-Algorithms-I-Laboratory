//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    08-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

void selectionStart(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) // index 0
    {
        int min = i;
        for (int j = i + 1; j < n; j++) // index 1
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
}

void sum(int arr[], int N)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }
    cout << "Total sum:  " << sum << endl;
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

    int arr[n];
    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter valus of N: " << endl;
    int N;

    cin >> N;

    cout << "Original Array" << endl;
    print(arr, n);

    cout << "Array after Sorting " << endl;
    selectionStart(arr, n);
    print(arr, n);
    sum(arr, N);
}
