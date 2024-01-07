//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    14-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

/* SELECTION SORT & MEIDAN*/

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

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void findmedian(int a[], int n)
{
    int median;
    if (n / 2 != 0)
    {
        int median = a[n / 2];
        cout << "Median is " << median << endl;
    }
    else
    {
        median = a[(n - 1) / 2] + a[n / 2];
        cout << "Median is " << median << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the size of array     ";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array     ";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Orginal Array      ";
    print(a, n);

    seletionSort(a, n);
    cout << "Sorted Array       ";
    print(a, n);
    findmedian(a, n);
    return 0;
}
