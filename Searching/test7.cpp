//        ****************  Author :  Khan Israk Ahmed  *************************\
//        ****************  Date:    01-06-2023     *************************\


#include <bits/stdc++.h>
using namespace std;

int findSquareRoot(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}

int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 4;

    int insertPosition = findSquareRoot(nums, target);

    int sqrtValue;
    if (insertPosition < nums.size() && nums[insertPosition] == target)
    {
        sqrtValue = sqrt(target);
    }
    else
    {
        sqrtValue = sqrt(target - 1);
    }

    cout << "Square root of " << target << ": " << sqrtValue << endl;
    cout << "Insert position of " << target << ": " << insertPosition << endl;

    return 0;
}
