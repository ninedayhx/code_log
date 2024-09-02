// tag: binary_search 二分查找 array
#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    if (target == nums[right])
    {
        return right;
    }
    if (target > nums[right])
    {
        return right + 1;
    }
    if (target <= nums[0])
    {
        return 0;
    }
    int mid = 0;

    // 对于这种找区间的题，不能通过使用二分搜索那样
    // 将left 或 mid向左向右缩进一格，缩进一格就可能会漏掉
    // 应该直接将mid作为left或者right
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (target == nums[mid])
        {
            return mid;
        }
        if (right - left == 1 && target < nums[right] && target > nums[left])
        {
            return left + 1;
        }
        if (right == left)
        {
            if (target > nums[left])
            {
                return left + 1;
            }
            else if (target == nums[left])
            {
                return left;
            }
            else
                return left - 1;
        }
        if (target > nums[mid])
        {
            left = mid;
        }
        if (target < nums[mid])
        {
            right = mid;
        }
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    vector<int> n;
    while (1)
    {
        int x;
        cin >> x;
        n.emplace_back(x);
        if (cin.get() == '\n')
            break;
    }

    cout << searchInsert(n, t);
}