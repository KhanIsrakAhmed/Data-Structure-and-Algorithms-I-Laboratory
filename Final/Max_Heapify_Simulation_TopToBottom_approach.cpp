//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    21-07-2023     *************************\

#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int len)
{
    cout << "Printing Array :  ";
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int Total_Call_count_of_maxheapify = 0;

// heapify function for the max heap
// top to bottom approach
void maxheapify(int arr[], int size, int index) //    maxheapify (arr, length - 1, i)
{
    int leftChild = index * 2;
    int rightChild = index * 2 + 1;

    // debug code
    {
        cout << "Index " << index << endl;
        if (leftChild <= size)
            cout << "Left child = " << arr[leftChild] << "    ";
        if (rightChild <= size)
            cout << "Right child = " << arr[rightChild];
        cout << endl;
    }

    int largest = index; // parent

    if (leftChild <= size && arr[largest] < arr[leftChild])
    {
        largest = leftChild;
    }

    if (rightChild <= size && arr[largest] < arr[rightChild])
    {
        largest = rightChild;
    }

    if (largest != index)
    {
        cout << "swap  " << arr[largest] << " < - - > " << arr[index] << endl;
        swap(arr[largest], arr[index]);
        printArray(arr, size + 1);
        cout << endl;

        cout << "------ Recursion ------" << endl;
        Total_Call_count_of_maxheapify++;
        maxheapify(arr, size, largest);
    }
    cout << endl;
}

void buildMaxHeap(int arr[], int length)
{
    for (int i = length / 2; i >= 1; i--)
    {
        cout << "Calling maxHeapify  index = " << i << "   value = " << arr[i] << endl;
        cout << "``````````````````````````````````````````" << endl;
        Total_Call_count_of_maxheapify++;
        maxheapify(arr, length - 1, i);
    }
}

int32_t main()
{

    // check this all arrays visualization onr by one to understand heapify clearly

    // int arr[] = {-1, 123, 33, 32134, 343, 31, 3, 34, 5, 44, 42, 4};
    // int arr[] = {-1, 123, 33, 32134, 343, 31, 3, 34, 5, 44, 42, 4455454};
    int arr[] = {-1, 9, 3, 2, 4, 1, 16, 14, 10, 8, 7}; // Good Example
    // int arr[] = {-1, 50,30,15,19,20,10,5,2};
    // int arr[] = {-1, 12, 11, 13, 5, 6, 7};
    // int arr[] = {-1, 2, 10, 4, 7, 1, 8, 9, 3, 6, 5};

    int length = sizeof(arr) / sizeof(arr[0]);

    cout << endl;
    cout << "Given Array : ";
    printArray(arr, length);

    cout << "Length " << length << endl;
    cout << endl;
    cout << "---------- Calling build Max Heap Function --------" << endl;
    buildMaxHeap(arr, length);
    cout << endl;

    cout << "Final Print " << endl;
    printArray(arr, length);
    cout << endl;

    cout << "Total_Call_count_of_maxheapify  " << Total_Call_count_of_maxheapify << endl;
    cout << endl;

    return 0;
}
