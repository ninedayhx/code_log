// tag: backtrack dfs 子集型回溯
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 子集型回溯，找一个简单的例子写一遍搜索树，马上就明白怎么做了，但是这里的回溯过程是通
 * 过复制path数组实现的,每进一次递归，都会使得path被复制一次，所以空间复杂度很高，这样隐式的进
 * 行了回溯，但是还是动态的维护一个path数组，对path数组进行增加减少操作实现回溯，能够降低空间
 * 复杂度
 * @param nums
 * @return vector<vector<int>>
 */
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> path;
    auto dfs = [&](auto &&dfs, int i, vector<int> sub)
    {
        // dfs退出条件
        if (i == n)
        {
            ans.emplace_back(sub);
            return;
        }
        // 不选
        dfs(dfs, i + 1, sub);
        // 选
        sub.emplace_back(nums[i]);
        dfs(dfs, i + 1, sub);
    };
    dfs(dfs, 0, path);
    return ans;
}

/**
 * @brief 通过选择和不选择nums[i]，就会有2^(i+1)种选择，那么这里dfs的入口参数就是这个索引i
 * 那么当dfs完成对nums的遍历后，也就是i==n时，就是dfs的终止条件，
 * 以上就确定了dfs的两个要素
 * 那么回溯，就表现在选择和不选择时，对path数组的维护过程，不选择时，path没有被更改，自然不需要
 * 进行回溯，当选择当前元素时，path元素被更改，自然需要进行回溯
 *
 * * 时间复杂度 ：搜索过程是一颗满二叉树，节点总数是 2^n, 加上每次复制path的时间，共为O(n*2^n)
 * * 空间复杂度 ：显然是O(n)
 * @param nums
 * @return vector<vector<int>>
 */
vector<vector<int>> subsets_op(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> path;
    auto dfs = [&](auto &&dfs, int i)
    {
        // dfs退出条件
        if (i == n)
        {
            ans.emplace_back(path);
            return;
        }
        // 不选, 则无需回溯
        dfs(dfs, i + 1);
        // 选， 则进行回溯
        path.emplace_back(nums[i]);
        dfs(dfs, i + 1);
        path.pop_back();
    };
    dfs(dfs, 0);
    return ans;
}

int main()
{
    vector<int> num;
    while (1)
    {
        int x;
        cin >> x;
        num.emplace_back(x);
        if (cin.get() == '\n')
            break;
    }
    auto ans = subsets(num);
    for (auto &v : ans)
    {
        for (auto &i : v)
        {
            cout << ' ';
        }
        cout << endl;
    }
}