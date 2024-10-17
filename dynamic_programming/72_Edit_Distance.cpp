// tag:
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief dfs记忆化搜索，抽象为选和不选，dfs(i，j)表示s和t,前i,j个字符之间的编辑距离
 * 如果 s[i] == s[j] 那么无需编辑，问题从dfs(i,j)=dfs(i-1,j-1)
 * 如果 s[i] != s[j] 那么有三种编辑方式
 *      1.删除s[i] 删除s[i]等于不选s[i] 问题缩减到dfs(i-1,j)
 *      2.插入s[i] 插入s[i]一定是插入t[j]处的字母 也就是等价于删除t[j]处的字母，等于不选j
 *        问题缩减到dfs(i,j-1)
 *      3.修改s[i]，修改s[i]要实现最小编辑距离一定是直接将s[i]修改为t[j],等价于同时删除s[i]
 *        t[j]那么问题直接缩减为dfs(i-1,j-1)
 *      要最小化当前操作数，那么就是从三种操作中选取最小的那个
 *  即dfs(i,j) = min(dfs(i-1,j),dfs(i,j-1),dfs(i-1,j-1))+1
 * @param word1
 * @param word2
 * @return int
 */
int minDistance(string word1, string word2)
{
    int m = word1.size();
    int n = word2.size();

    vector<vector<int>> mem(m, vector<int>(n, -1));
    auto dfs = [&](auto &&dfs, int i, int j)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (mem[i][j] != -1)
            return mem[i][j];
        if (word1[i] == word2[j])
        {
            mem[i][j] = dfs(dfs, i - 1, j - 1);
        }
        else
        {
            mem[i][j] = min(dfs(dfs, i - 1, j), dfs(dfs, i, j - 1), dfs(dfs, i - 1, j - 1)) + 1;
        }
        return mem[i][j];
    };
    return dfs(dfs, m - 1, n - 1);
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << minDistance(s, t) << endl;
}