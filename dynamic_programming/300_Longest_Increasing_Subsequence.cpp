// tag: dp, 动态规划， greedy，贪心， LIS问题， 记忆化搜素，
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief dfs版最长递增子序列, 通过记忆化的方式优化首先确认dfs返回值的意义，就是以第i个元素为
 * 结尾的最长子序列长度，那么就可以将这个问题缩减为，从第i个元素往前找的到前面比他小的元素中子序
 * 列最长的那个，这样就表述为一个递推的子问题，就可以通过深度优先搜索的方式进行递归，然后存在重复
 * 计算的情况，所以使用记忆化数组简化计算
 * @param nums
 * @return int
 */
int lengthOfLIS_dfs_mem(vector<int> nums)
{
    int n = nums.size();
    // 记忆化数组，存储了计算过程中以nums[i]为结尾元素的最长递增子序列长度
    vector<int> mem(n, 0);
    auto dfs = [&](auto &&dfs, int i) -> int
    {
        if (mem[i] > 0)
        {
            return mem[i];
        }
        // 使用的是引用
        int &res = mem[i];
        int j = i - 1;
        // 找第i个元素之前的元素中，具有最长的子序列的那个，然后就把问题缩减了
        while (j >= 0)
        {
            if (nums[i] > nums[j])
            {
                res = max(res, dfs(dfs, j));
            }
            --j;
        }
        res++;
        return res;
    };
    // 对所有元素都求一遍LIS, 如果只求最后一个元素的LIS,
    // 递归的过程中可能会漏掉比它大的元素，所以要对所有元素递归
    for (int i = 0; i < n; ++i)
    {
        dfs(dfs, i);
    }
    // 找出所有元素中最长的LIS长度
    return *max_element(mem.begin(), mem.end());
}

/**
 * @brief 递推的解法
 * @param nums
 * @return int
 */
int lengthOfLIS_dp(vector<int> nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i)
    {
        int j = i - 1;
        while (j >= 0)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j]);
            }
            --j;
        }
        dp[i]++;
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
    cout << lengthOfLIS_dp(nums) << endl;
}