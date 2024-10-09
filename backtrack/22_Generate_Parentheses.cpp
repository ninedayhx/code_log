// tag: 动态规划 dp 回溯 组合型回溯
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 等于是一个长为2n的数组，数组中必须要有一半'('一半')'，那么就把填入'('当作不选，填入
 * ')'当作选，那么当'('数量超过一半时，就必须填入')',
 * 所以dfs的参数包含两个，
 * 第一是数组索引i,表示填充到第几个位置了
 * 第二是已填入数组的'('数量 left
 * 而dfs的边界条件是i=2n 记录path
 * left>n时，则剩下的全选
 * left>=i-left+1 时也就是当前左括号的数量大于右括号的数量时
 * @param n
 * @return vector<string>
 */
vector<string> generateParenthesis_bt(int n)
{
    int m = 2 * n;
    vector<string> ans;
    string path(m, '0');
    auto dfs = [&](auto &&dfs, int i, int left) -> void
    {
        if (i == m && left == n)
        {
            ans.emplace_back(path);
            return;
        }
        if (left == n)
        {
            path[i] = ')';
            dfs(dfs, i + 1, left);
        }
        else
        {
            path[i] = '('; // 选'('
            dfs(dfs, i + 1, left + 1);
            if (left >= i - left + 1) // 左括号的个数必须大于右括号的个数，才能选右括号
            {
                path[i] = ')'; // 选')',直接覆盖实现回溯
                dfs(dfs, i + 1, left);
            }
        }
    };
    dfs(dfs, 0, 0);
    return ans;
}

int main()
{
    int x;
    cin >> x;
    auto ans = generateParenthesis_bt(x);
    for (auto &s : ans)
    {
        cout << s << ' ';
    }
    cout << endl;
}