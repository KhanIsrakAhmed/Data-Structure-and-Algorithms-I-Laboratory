#include <iostream>
using namespace std;

/*  6.	Find the number of occurrences of a particular element */

void occurrences(int arr[], int n, int k)
{
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        if (k == arr[i])
        {
            p = p + 1; // increment
        }
    }
    cout << "Output:     " << p << endl;
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

    cout << "Enter valus of k: " << endl;
    int k;

    cin >> k;

    cout << "Original Array" << endl;
    print(arr, n);
    occurrences(arr, n, k);
}
