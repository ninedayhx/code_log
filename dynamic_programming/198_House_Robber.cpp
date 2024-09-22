// tag: 动态规划 dp 记忆化搜索 背包问题
#include <bits/stdc++.h>

using namespace std;

int dfs(vector<int> nums, int n)
{
    if (n < 0)
    {
        return 0;
    }
    // 返回条件即为，如果选第n个节点，则当前的最大金额就是前n-2个节点的总金额
    // 如果不选第n个节点，则当前最大金额就是前n-1个节点的总金额
    // 则当前节点的最大金额就是这两种方式获取的最大金额，
    // 按照这种方式不断向前去迭代
    return max(dfs(nums, n - 1), dfs(nums, n - 2) + nums[n]);
}

int rob(vector<int> nums)
{
    return dfs(nums, nums.size() - 1);
}

int rob_mem(vector<int> nums)
{
    int n = nums.size();
    // 记忆以前递归过的位置，使用数组作为hash表。
    // -1表示之前没有递归过
    vector<int> mem(n, -1);
    function<int(int)> dfs = [&](int i) -> int
    {
        if (i < 0)
            return 0;
        if (mem[i] != -1)
            return mem[i];
        mem[i] = max(dfs(i - 1), dfs(i - 2) + nums[i]);
        return mem[i];
    };
    return dfs(n - 1);
}
int rob_dp(vector<int> nums)
{
    int n = nums.size();
    vector<int> f(n + 2, 0);
    for (int i = 2; i < n + 2; ++i)
    {
        f[i] = max(f[i - 1], f[i - 2] + nums[i - 2]);
    }
    return f[n - 1 + 2];
}

int rob_dp_opt(vector<int> nums)
{
    int n = nums.size();
    int f0 = 0, f1 = 0;
    for (int i = 0; i < n; ++i)
    {
        int f2 = max(f1, f0 + nums[i]);
        f0 = f1;
        f1 = f2;
    }
    return f1;
}

int main()
{
    int x = 0;
    cin >> x;
    for (int k = 0; k < x; ++k)
    {
        int n = 0;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> nums[i];
        }
        cout << rob(nums);
    }
}