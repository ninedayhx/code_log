// tag: dp, 动态规划， greedy，贪心， LIS问题，
#include <bits/stdc++.h>

using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n);
    for (int right = 0; right < n; ++right)
    {
        dp[right] = 1;
        for (int left = 0; left < right; ++left)
        {
            if (nums[left] < nums[right])
            {
                dp[right] = max(dp[right], dp[left] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    vector<int> nums;
    while (1)
    {
        int x;
        cin >> x;
        nums.emplace_back(x);
        if (cin.get() == '\n')
            break;
    }
    cout << lengthOfLIS(nums) << endl;
}