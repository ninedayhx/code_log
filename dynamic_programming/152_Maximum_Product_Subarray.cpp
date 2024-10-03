// tag: 动态规划，记忆化搜索，dp
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 通过同时维护以每一个元素结尾的最大子数组乘积和最小子数组乘积，实现该问题，为何要维护
 * 最小子数组呢，这是为了处理乘积为负数的情况
 * @param nums
 * @return int
 */
int maxProduct(vector<int> &nums)
{
    int n = nums.size();
    vector<int> max_ans(n + 1, INT_MIN), min_ans(n + 1, INT_MAX);
    max_ans[0] = 1;
    min_ans[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        max_ans[i] = max(max_ans[i - 1] * nums[i - 1], nums[i - 1]);
        max_ans[i] = max(min_ans[i - 1] * nums[i - 1], max_ans[i]);
        min_ans[i] = min(min_ans[i - 1] * nums[i - 1], nums[i - 1]);
        min_ans[i] = min(max_ans[i - 1] * nums[i - 1], min_ans[i]);
    }
    return *max_element(max_ans.begin() + 1, max_ans.end());
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
    cout << maxProduct(nums);
}