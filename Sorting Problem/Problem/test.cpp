//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    11-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

/** Selection sort & median*/

void seletionSort(int a[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++) // index 0
    {
        min = i;
        for (j = i + 1; j < n; j++) // index 1
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
void maximum(int arr[], int b)
{
    int max = arr[0];
    for (int i = 1; i < b; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << "Maximum element is " << max << endl;
}

void minimum(int arr[], int n)
{
    int min = arr[0];
    int index;
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            index = i;
        }
    }

    cout << "Minimum element is " << min << endl;
    cout << "Index of minimum element is     " << index << endl;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// void findMedian(int arr[], int n)
// {
//     int median;
//     if (n % 2 != 0)
//     {
//         median = arr[n / 2];
//         cout << "Median is " << median << endl;
//     }
//     else
//     {
//         median = arr[(n - 1) / 2] + arr[n / 2];
//         cout << "Median is " << median << endl;
//     }
// }

// void mindiff(int arr[], int n)
// {
//     int min = arr[0];
//     int index;
//     for (int i = 1; i < n; i++)
//     {
//         if (min > arr[i])
//         {
//             min = arr[i];
//             index = i;
//         }
//     }
//     cout << "Pairs with smallest difference  " << min << endl;
// }

int main()
{
    cout << " Keeping" << endl;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Original Array" << endl;
    printArray(arr, n);

    cout << "Array after Sorting " << endl;
    seletionSort(arr, n);
    printArray(arr, n);
    maximum(arr, n);
    minimum(arr, n);
    // mindiff(arr, n);

    // findMedian(arr, n);

    return 0;
}