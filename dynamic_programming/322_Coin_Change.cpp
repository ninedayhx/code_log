// tag: dp 动态规划 记忆化搜索
#include <bits/stdc++.h>

using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
    {
        for (int j = 0; j < coins.size(); --j)
        {
            if (coins[j] < i)
            {
                dp[i] = min(dp[i], dp[i - coins[j] + 1]);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main()
{
    while (1)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        int target;
        cin >> target;
        cout << coinChange(nums, target) << endl;
    }
}