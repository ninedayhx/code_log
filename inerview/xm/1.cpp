// tag: 动态规划
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 思路就是把串分为左半边和右半边，左半边取dp[j], 右半边就是一个括号包上dp[i-j-2],括号
 *        括号有k种选择，则dp[i] = sum_j=0-n-1 dp[j]*dp[i-j-2]*k
 * @param n
 * @param k
 * @return int
 */
int maxArrays(int n, int k)
{
    vector<int> dp(n / 2 + 1);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            dp[i] += dp[j] * dp[i - j - 1] * k;
        }
    }
    return dp[n / 2];
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << maxArrays(n, k);
}