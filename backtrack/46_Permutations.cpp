// tag: backtrack dfs
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<int> vis = {};
    vector<vector<int>> ans = {};
    vector<int> sub = {};
    /**
     * @brief 深度优先搜索，递归版
     *
     * @param n 数组
     * @param len 当前排列结果的长度 0-n
     *            长度大于总长度，为结束条件
     */
    void dfs(vector<int> &n, int len)
    {
        if (len > n.size())
            return;
        if (len == n.size())
        { // 满了 把当前排列结果放到总结果里
            ans.emplace_back(sub);
        }
        // 遍历一边
        for (int i = 0; i < n.size(); ++i)
        {
            if (vis[i] == 0) // 没有访问过
            {
                sub[len] = n[i];
                vis[i] = 1;
                dfs(n, len + 1);
                vis[i] = 0; // 相当于回溯
                sub[len] = -1;
            }
        }
        return;
    }

    void backtrack(vector<int> &n, int unvis)
    {
        int len = n.size();
        // 未访问位置到了数组尾部，说明完成了
        if (unvis == len)
        {
            ans.push_back(n);
            return;
        }
        // 遍历未访问过的
        for (int i = unvis; i < len; ++i)
        {
            // 交换第一个未访问过的和其他遍历的
            swap(n[unvis], n[i]);
            // 更新未访问过的
            backtrack(n, unvis + 1);
            // 回溯
            swap(n[unvis], n[i]);
        }
    }

public:
    vector<vector<int>> permute_dfs(vector<int> &nums)
    {
        int n = nums.size();
        vis.resize(n, 0);
        sub.resize(n, -1);
        dfs(nums, 0);
        return ans;
    }

    vector<vector<int>> permute_backtrack(vector<int> &nums)
    {
        backtrack(nums, 0);
        return ans;
    }
};

int main()
{
    vector<int> nums;
    while (1)
    {
        int x;
        cin >> x;
        nums.push_back(x);
        if (cin.get() == '\n')
            break;
    }
    Solution s;
    auto res = s.permute_backtrack(nums);
    for (auto &v : res)
    {
        for (auto &i : v)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
}