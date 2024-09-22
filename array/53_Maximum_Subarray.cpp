// tag: array  动态规划
#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    // 将数组第一个初始化为最大值
    int pre = 0, maxAns = nums[0];
    for (auto &i : nums)
    {
        // 如果加的值是得整个值大了，那么就记录下来
        pre = max(pre + i, i);
        maxAns = max(maxAns, pre);
    }
    return maxAns;
}

/**
 * @brief 前缀和
 *
 * @return int
 */
int maxSubArray_prevsum(vector<int> &nums)
{
    vector<int> presum(nums.size() + 1, 0);
    presum[0] = 0;
    for (int i = 1; i <= nums.size(); ++i)
    {
        presum[i] = nums[i - 1] + presum[i - 1];
    }
    // 此时的最大连续子数组和就变为了找到前缀和数组中最大的那个，和最小的那个，也就是使用贪心算法
    // 维护最小前缀和,什么都不选时，最小前缀和是0，所以初始为0
    int min_pre = 0;
    int max_sum = INT_MIN;
    // index 从1开始，保证至少会选一个元素
    for (int i = 1; i < presum.size(); ++i)
    {
        // 先按照上一次的最小值去更新最大前缀和，保证至少会选一个元素
        // 如果先更新最小值，那么就可能当前值就是最小值，然后就会出现不选元素的错误情况
        max_sum = max(max_sum, presum[i] - min_pre);
        min_pre = min(min_pre, presum[i]);
    }
    return max_sum;
}

/**
 * @brief
 *
 * @param nums
 * @return int
 */
int maxSubArray_prevsum_opt(vector<int> &nums)
{
    // 初始时，什么都不选，前缀和为0
    int presum = 0;
    int maxsum = INT_MIN;
    // 初始时，最小前缀和为0
    int minpre = 0;
    for (auto &i : nums)
    {
        // 滚动更新前缀和
        presum += i;
        // 先使用未更新的最小前缀和求解最大的子数组和
        // 然后再更新最小前缀和，这样就能保证不会出现没有选元素的情况
        maxsum = max(maxsum, presum - minpre);
        minpre = min(minpre, presum);
    }
    return maxsum;
}

int main()
{
    vector<int> num;
    while (1)
    {
        int x;
        cin >> x;
        num.push_back(x);
        if (cin.get() == '\n')
            break;
    }
    cout << maxSubArray(num) << endl;
}