// tag: array 计数排序
#include <bits/stdc++.h>

using namespace std;

int hindex(vector<int> nums)
{
    sort(nums.begin(), nums.end(), greater<int>());
    for (auto &i : nums)
    {
        cout << i << ' ';
    }
    for (int i = 1; i <= nums.size(); ++i)
    {
        if (nums[i - 1] < i)
        {
            return i - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> cite(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> cite[i];
    }
    cout << hindex(cite);
}