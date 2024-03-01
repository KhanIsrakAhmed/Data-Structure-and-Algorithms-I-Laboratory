//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    09-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

/** bubble sort & stop if sorted*/

void bubbleSort(int arr[], int n)
{
    int count = 0;
    int loop = 0;
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
                count++;
                swapped = 1;
            }
        }

        if (swapped == 0)
        {
            break;
        }
        loop++;
    }
    cout << "The numbers of swapping: " << count << endl;
    cout << "The numbers of loop running: " << loop << endl;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
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

    cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}