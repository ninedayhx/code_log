// tag: 动态规划，dp 记忆化搜索
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief dfs记忆化搜索，抽象为两个选和不选，选和不选的索引记为 i,j 这就是dfs的入口参数，dfs
 * 的记录的数据是已经选过的数中公共子序列的长度，
 * 当text1[i]==text[j]时dfs长度加一，此时自动选择i和j，所以子问题就递归到dfs（i-1，j-1）
 * 当text1[i]!=text[j]时，那么dfs(i,j)的子问题就是选text1的第i个值dfs(i-1,j)还是选
 * text2的第j个值dfs(j,i-1)，由于我们希望搜索到最长的子序列，所以在两个方向中，我们就选择最大
 * 的那个即 max(dfs(i-1,j), dfs(i,j-1))
 * 最后问题的边界条件就是i，j任意一个超出边界，i<0或j<0
 * @param text1
 * @param text2
 * @return int
 */
int longestCommonSubsequence_dfs(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    int ans = 0;
    vector<vector<int>> mem(n, vector<int>(m, -1));
    auto dfs = [&](auto &&dfs, int i, int j) -> int
    {
        if (i < 0 || j < 0)
            return 0;
        if (mem[i][j] != -1)
            return mem[i][j];
        if (text1[i] == text2[j])
        {
            mem[i][j] = dfs(dfs, i - 1, j - 1) + 1;
        }
        else
        {
            mem[i][j] = max(dfs(dfs, i - 1, j), dfs(dfs, i, j - 1));
        }
        return mem[i][j];
    };
    return dfs(dfs, n - 1, m - 1);
}

/**
 * @brief 改写为递推dp
 * @param text1
 * @param text2
 * @return int
 */
int longestCommonSubsequence_dp(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    cout << longestCommonSubsequence_dfs(str1, str2);
}