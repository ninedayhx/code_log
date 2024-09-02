// tag: binary_search 二分搜索 array
#include <bits/stdc++.h>

using namespace std;

int findFisrtIdx(vector<int> n, int t)
{
    int l = 0, r = n.size() - 1;
    int ans = -1;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (t == n[m])
        {
            ans = m;
            r = m - 1; // 因为要找第一个出现的目标值，
            // 所以在找到目标值后，把右边界继续向左迭代，直到退出
            // 这样就能找到最左边的目标值
        }
        else if (t > n[m])
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return ans;
}

int findLastIdx(vector<int> n, int t)
{
    int l = 0, r = n.size() - 1;
    int ans = -1;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        if (t == n[m])
        {
            ans = m;
            l = m + 1; // 因为要找第一个出现的目标值，
            // 所以在找到目标值后，把左边界继续向右迭代，直到退出
            // 这样就能找到最右边的目标值
        }
        else if (t > n[m])
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return ans;
}

// 本质上是找第一个大于等于目标值的位置和第一个大于目标值的位置
// 那么如果目标值在数组中如果有多个，二分搜索如何保证找到的是第一个值呢
// 按道理来说，普通的二分搜索没法保证是第一个值
vector<int> searchRange(vector<int> &nums, int target)
{
    return {findFisrtIdx(nums, target), findLastIdx(nums, target)};
}

int main()
{
    vector<int> num;
    while (1)
    {
        int x;
        cin >> x;
        num.emplace_back(x);
        if (cin.get() == '\n')
            break;
    }
    int t;
    cin >> t;
    auto res = searchRange(num, t);
    cout << res[0] << res[1] << endl;
}