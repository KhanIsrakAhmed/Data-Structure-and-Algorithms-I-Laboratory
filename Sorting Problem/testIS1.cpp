#include <iostream>
using namespace std;

/** Insertion sort & stop if sorted*/

void insertion(int a[], int n)
{
    int count = 0;
    int loop = 0;

    for (int i = 1; i < n; i++) // START WITH INDEX 1
    {

        int key = a[i];
        int j = i - 1; // 0 index
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j]; // index 1 = index 0
            j = j - 1;
            count++;
        }

        a[j + 1] = key;

        loop++;
    }
    cout << "The numbers of swapping: " << count << endl;
    cout << "The numbers of loop running: " << loop << endl;
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

    insertion(a, n);
    cout << "After insertion     ";
    print(a, n);
    return 0;
}
