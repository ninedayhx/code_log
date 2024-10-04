// tag: backtrack dfs dp 动态规划 子集型回溯 完全背包
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 这道题可以当作完全背包来做，转化为选和不选，
 * 入口参数分别为 选择范围i,以及背包容量c，即dfs(i，c)
 * 如果i<=c, 则有两种选择
 *      1.选择当前目标，则问题缩减为 dfs(i,c-i)+1, i保持不变表示元素可以被多次选择
 *      2.不选择当前目标，则问题缩减为 dfs(i-1,c)
 * 如果i>c 则只能不选择当前目标
 *      问题缩减为dfs(i-1,c)
 * 终止条件为 i=0 且 c=0, 则path 入 ans;
 *           i=0但c>0 终止dfs 抛弃
 * @param candidates
 * @param target
 * @return vector<vector<int>>
 */
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    int n = candidates.size();
    vector<vector<int>> ans;
    vector<int> path;
    auto dfs = [&](auto &&dfs, int i, int c)
    {
        if (i == 0)
        {
            if (c == 0)
            {
                ans.emplace_back(path);
            }
            return;
        }
        if (candidates[i - 1] > c)
        {
            // 只能不选
            dfs(dfs, i - 1, c);
        }
        else
        {
            // 不选 无需回溯
            dfs(dfs, i - 1, c);
            // 选 需要回溯
            path.emplace_back(candidates[i - 1]);
            dfs(dfs, i, c - candidates[i - 1]);
            path.pop_back();
        }
    };
    dfs(dfs, n, target);
    return ans;
}

int main()
{
    vector<int> cand;
    while (1)
    {
        int x;
        cin >> x;
        cand.emplace_back(x);
        if (cin.get() == '\n')
            break;
    }
    int t;
    cin >> t;
    auto ans = combinationSum(cand, t);
    for (auto &v : ans)
    {
        for (auto &i : v)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
}