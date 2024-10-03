// tag: dp 动态规划 完全背包
#include <bits/stdc++.h>

using namespace std;

// 给你一个整数 n ，返回和为 n 的完全平方数的最少数量。

/**
 * @brief 深度优先搜索开始理解完全背包
 * 对于这道题而言，其实就是从小于n的完全平方数中，选取若干个数(可以重复选取)，使其和等于j，那么
 * 就隐含了选与不选的规则在其中，对于这道题而言，深度搜索条件就可以表述为
 * dfs(i,j)，这个问题的搜索方向就是选择第i个数和不选择第i个数
 * 1. 如果选择了第i个数，那么想要组成j, 就需要继续从前i个数中选择完全平方数组成j-i*i，那么这种
 * 选择的完全平方数的数量就是 1+dfs(i, j-i*i)，1就表示i*i这个数
 * 2. 如果不选择第i个数，那么就是从前i-1个数中继续挑选完全平方数，那么这种选择的完全平方数的数
 * 量就是dfs(i-1, j)
 * * 搜索方向选择:  从这两种选择中，选择较小数量的那个，就满足了题目所要求的最少数量的搜索方向
 * * 终止条件选择:  当i<=0的时候，dfs(0,j) = 0;
 * *              当i*i>j的时候，就继续向前寻找 dfs(i,j) = dfs(i-1, j);
 * 那么如何确定这个i呢，能够组成n的最大的完全平方数，一定满足i*i<j这个条件，所以i的取值范围也就
 * 知道了
 * @param n
 * @return int
 */
int numSquares_dfs(int n)
{
    auto dfs = [&](auto &&dfs, int i, int j) -> int
    {
        if (i <= 0)
            // 注意这里的返回值，必须要这样处理，为啥呢，因为当i=0,j=0时，此时的方案数为0
            // 是为了应对当i*i==n,然后会递归进子问题 dfs(0,0)此时应当方案数为0
            // 而当i=0 j>0时，认为此时的方案数为无穷大，这样就能保证当i=1时，必须选择i=1这个
            // 数，而i=0,j>0的时候方案数为无穷其实也是满足了数学上的认知
            return j == 0 ? 0 : INT_MAX;
        if (i * i > j)
            return dfs(dfs, i - 1, j);
        return min(dfs(dfs, i, j - i * i) + 1, dfs(dfs, i - 1, j));
    };
    return dfs(dfs, sqrt(n), n);
}

/**
 * @brief 通过使用记忆数组对dfs过程进行优化, 完全背包的深度优先搜索过程有两个入参，所以使用二
 * 维数组进行记忆
 *
 * 如何计算深度优先搜索的时间空间复杂度
 * 动态规划的时间复杂度 = 状态个数 × 单个状态的计算时间。
 *
 * 其实就是1：1 翻译到递推表达式的时间和空间复杂度
 * @param n
 * @return int
 */
int numSquares_dfs_mem(int n)
{
    vector<vector<int>> mem(n + 1, vector<int>(n + 1, -1));
    auto dfs = [&](auto &&dfs, int i, int j) -> int
    {
        if (i <= 0)
            return ((j == 0) ? 0 : INT_MAX);
        int &cur = mem[i][j]; // 记忆化数组必须要在边界条件之前，否则会越界
        if (cur != -1)
            return cur;
        if (i * i > j)
            cur = dfs(dfs, i - 1, j);
        else
            cur = min(dfs(dfs, i - 1, j), dfs(dfs, i, j - i * i) + 1);
        return cur;
    };
    return dfs(dfs, sqrt(n), n);
}

/**
 * @brief 从深度优先搜索翻译到一般形式的递推，但是时间复杂度和空间复杂度都太高了
 * 时间复杂度 o(n√n) 空间复杂度 o(n√n)
 * @param n
 * @return int
 */
int numSquares_dp(int n)
{
    vector<vector<int>> dp(sqrt(n) + 1, vector<int>(n + 1, -1));
    for (int i = 0; i * i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == 0)
            {
                dp[i][j] = j == 0 ? 0 : INT_MAX;
            }
            else if (i * i > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - i * i] + 1);
            }
        }
    }
    return dp[sqrt(n)][n];
}

/**
 * @brief 滚动数组优化版的递推的动态规划解法，对空间复杂度进行优化
 *        todo
 *        只需维护一个动态数组
 * @param n
 * @return int
 */
int numSquares_dp_op(int n)
{
    vector<int> dp(n + 1, -1);
    for (int i = 0; i * i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (i == 0)
            {
                dp[j] = (j == 0 ? 0 : INT_MAX);
            }
            else if (i * i > j)
            {
                dp[j] = dp[j];
            }
            else
            {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    cout << numSquares_dfs(n) << endl;
    cout << numSquares_dfs_mem(n) << endl;
    cout << numSquares_dp(n) << endl;
}