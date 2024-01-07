#include <iostream>
using namespace std;

/*	Find the number of elements in the longest subset having successive */

int longestSuccessiveSubset(int arr[], int n)
{
    sort(arr, arr + n);
    int count = 1;
    int maxCount = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1] + 1)
        {
            count++;
            if (count > maxCount)
            {
                maxCount = count;
            }
        }
        else
        {
            count = 1;
        }
    }

    return maxCount;
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

    int result = longestSuccessiveSubset(arr, n);
    cout << "Number of elements in the longest subset with successive numbers: " << result << endl;

    return 0;
}
