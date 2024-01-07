#include <iostream>
using namespace std;

/* Find a sorted partition of length k from an unsorted array of n elements  */

void insertion(int a[], int n, int k)
{

    for (int i = 1; i < k; i++) // START WITH INDEX 1
    {

        int key = a[i];
        int j = i - 1; // 0 index
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j]; // index 1 = index 0
            j = j - 1;
        }

        a[j + 1] = key;
    }
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

    cout << "Array after Sorting " << endl;
    insertion(arr, n, k);
    print(arr, k);
}
