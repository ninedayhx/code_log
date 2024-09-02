// tag: binary_search 二分查找 array
#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    int ans = nums.size();
    // 对于这种找区间的题，不能通过使用二分搜索那样
    // 将left 或 mid向左向右缩进一格，缩进一格就可能会漏掉
    // 应该直接将mid作为left或者right
    while (left <= right)
    {
        mid = (right + left) >> 1;
        if (target <= nums[mid])
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
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