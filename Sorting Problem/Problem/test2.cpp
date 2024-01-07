#include <iostream>
using namespace std;

void bobbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0;

        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
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
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while (true)
    {
        cout << "Enter Enter a number: ";
        cin >> k;
        if (k <= n)
        {
            break; // Break the loop if k is valid
        }
        cout << "Invalid input! Please enter a value less than or equal to 10." << endl;
    }

    cout << "Original Array" << endl;
    print(arr, n);

    cout << "Array after Sorting " << endl;
    bobbleSort(arr, n);
    print(arr, n);

    cout << k << " th element     " << endl;

    cout << arr[k - 1] << " ";
}
