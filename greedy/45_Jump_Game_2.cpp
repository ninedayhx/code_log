// tag: greedy 贪心算法
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int minJump = INT_MAX;
    void dfs(vector<int> nums, int i, int jump)
    {
        int len = i + nums[i];
        if (len >= nums.size() - 1)
        {
            minJump = min(minJump, jump + 1);
            return;
        }
        if (nums[i] == 0)
            return;
        for (int x = len; x >= i + 1; --x)
        {
            dfs(nums, x, jump + 1);
        }
    }

public:
    /**
     * @brief 使用递归进行搜索会超时
     *
     * @param nums
     * @return int
     */
    int jump_greedy_dfs(vector<int> &nums)
    {
        dfs(nums, 0, 0);
        return minJump;
    }

    int jump(vector<int> nums)
    {
        if (nums.size() == 1)
            return 0;
        int jump = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int len = i + nums[i];
            if (len >= nums.size() - 1)
            {
                return jump + 1;
            }

            // 下面的代码体现了贪心策略
            int greedy_idx = 0;
            int maxlen = 0;
            // 每次选择下一个能到达区间内中，能走的最远的那个
            for (int x = len; x >= i + 1; --x)
            {
                if (maxlen <= x + nums[x])
                {
                    greedy_idx = x;
                    maxlen = x + nums[x];
                }
            }
            i = greedy_idx - 1;
            ++jump;
        }
        return -1;
    }
};

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
    Solution s;
    cout << s.jump(nums) << endl;
}