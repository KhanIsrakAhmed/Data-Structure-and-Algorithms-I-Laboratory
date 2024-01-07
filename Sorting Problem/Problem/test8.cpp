//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    18-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;
/*  8.	Find the sum of n largest numbers from an unsorted array using bubble sort. */

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[min])
            { // Corrected comparison (sorting in descending order)
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

int sumOfLargestNumbers(int arr[], int n, int numLargest)
{
    selectionSort(arr, n);
    int totalSum = 0;
    for (int i = 0; i < numLargest; i++)
    {
        totalSum += arr[i];
    }
    return totalSum;
}

void printArray(int a[], int n)
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

    int numLargest;
    cout << "Enter the number : ";
    cin >> numLargest;

    cout << "Original Array: ";
    printArray(arr, n);

    selectionSort(arr, n);
    cout << "Array after Sorting: ";
    printArray(arr, n);

    int totalSum = sumOfLargestNumbers(arr, n, numLargest);
    cout << "Sum of the " << numLargest << " largest numbers: " << totalSum << endl;

    return 0;
}
