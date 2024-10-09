// tag: backtrack dfs 回溯 排列型回溯
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 排列型回溯，其实就是从目标集中选取元素填入n个有序空格中，当填入第i个空格，则下一个问
 * 题就缩减为从剩余未访问的元素中选取一个填入第i+1个空格，即
 * dfs(i, set)->dfs(i+1, set-x)
 * 即从set选取一个元素x填入第i个位置后，下一个子问题就变为，从set-x中选取一个元素填入第i+1个
 * 位置，使用一个标记数组来表示剩余元素
 * 所以dfs的参数有两个，一个是需要填入的位置i,一个是剩余元素集合，我们使用标记数组表示
 * 所以dfs的结束条件为 当i>=n时，说明path已经被填满，将搜索结果填入ans中
 * 
 * * 时间复杂度计算，先画出搜索树，然后计算搜索树的每一层的节点数量，为 \sum A_n^m,然后可以严
 * 格的计算出总节点数为 e*n！，再加上复制path所花的时间，总时间就是O(n*n!)
 * 
 * * 空间复杂度计算，除去结果用的空间，path和vis这个两个中间变量占用O(2n)
 * 
 * @param nums
 * @return vector<vector<int>>
 */
vector<vector<int>> permute_dfs(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> path(n);
    vector<int> used(n, 0);
    /**
     * @brief i 表示当前dfs需要填入path[i]位置，vis表示什么元素已经被访问过
     */
    auto dfs = [&](auto &&dfs, int i, vector<int> &vis)
    {
        if (i >= n)
        {
            ans.emplace_back(path);
            return;
        }
        // 遍历所有未被访问过的集合元素
        for (int j = 0; j < n && vis[j] == 0; ++j)
        {
            path[i] = nums[j];
            vis[j] = 1;           // 标记当前位置,
            dfs(dfs, i + 1, vis); // 然后进一步进行搜索
            vis[j] = 0;           // 搜索完成后进行回溯，恢复现场
        }
    };
    dfs(dfs, 0, used);
    return ans;
}

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
    auto res = permute_dfs(nums);
    for (auto &v : res)
    {
        for (auto &i : v)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
}