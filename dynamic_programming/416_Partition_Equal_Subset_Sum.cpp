// tag: 01背包 背包问题 动态规划
#include <bits/stdc++.h>

using namespace std;

// 原始维护2d表的动态规划
bool canPartition_2d(vector<int> &nums)
{
    int n = nums.size();
    // 如果数组长度为1 则不可能
    if (n < 2)
        return false;
    int sum = 0;
    for (auto &i : nums)
        sum += i;
    if (sum & 1 == 1) // 等价于sum%2==1
        return false;
    int target = sum / 2;
    // 因为数组中元素为正数，如果数组中最大元素大于target，则不可能
    if (*max_element(nums.begin(), nums.end()) > target)
        return false;
    // 默认全0初始化
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    // 容量为0 全置1
    for (int i = 0; i < n; ++i)
        dp[i][0] = 1;
    // 初始化dp的第一行
    dp[0][0] = 1;
    if (nums[0] <= target)
        dp[0][nums[0]] = 1;
    // 从第二行开始dp
    for (int i = 1; i < n; ++i)
    { // 遍历数组
        // dp的两种选择，
        // 1. 不将当前数组值加入背包,
        // 那么当前行背包的可能容量就是继承上一行背包的可能容量
        dp[i] = dp[i - 1];
        // 2. 将当前值加入背包,
        // 如果当前值超过了最大背包容量，则丢弃
        // 如当前值和其他可能的背包容量之和小于等于最大背包容量，
        // 则对应容量之和的位置为1，超过了就丢弃
        // 记得在上一行dp的基础上进行判断，因为这一行会被动态的改变
        for (int j = 0; j <= target; ++j)
        { // 遍历背包容量
            if (dp[i - 1][j] && (j + nums[i]) <= target)
            { // 当前容量有效且当前物品加上当前容量小于最大容量
                dp[i][j + nums[i]] = 1;
            }
        }
    }
    // 遍历到最后，dp中最后一个元素为真，说明能填满两个背包
    if (dp[n - 1][target] == 1)
        return true;
    return false;
}

// 维护二维的表本质上是在不断的更新一维的表，所以可以直接更新1维的表
bool canPartition_1d(vector<int> nums)
{
    int n = nums.size();
    if (n < 2)
        return false;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1 == 1)
        return false;
    int target = sum >> 1;
    if (*max_element(nums.begin(), nums.end()) > target)
        return false;
    vector<int> dp(target + 1);
    // init dp
    dp[0] = 1;
    if (nums[0] <= target)
        dp[nums[0]] = 1;
    for (int i = 1; i < n; ++i)
    {
        auto tmp = dp;
        for (int j = 0; j <= target; ++j)
        {
            if (tmp[j] && j + nums[i] <= target)
            {
                dp[j + nums[i]] = 1;
            }
        }
    }
    if (dp[target])
        return true;
    else
        return false;
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
    cout << canPartition_2d(nums) << endl;
    cout << canPartition_1d(nums) << endl;
}