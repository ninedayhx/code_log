// tag: dp 动态规划
#include <bits/stdc++.h>

using namespace std;

int numSquares(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    for (int i = 1; i < n; ++i)
    {
        int minSq = INT_MAX;
        for (int j = 1; j * j <= i; ++j)
        {
            minSq = min(minSq, dp[i - j * j]);
        }
        // 首先找所有的可能的j,这个j对应于j*j,那么j*j就是其中一个完全平方数，就是下面的+1
        // 然后找剩下的值中，也就是i-j*j中，具有最小完全平方数的那个，就是下面的minSq
        dp[i] = minSq + 1;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << numSquares(n);
}