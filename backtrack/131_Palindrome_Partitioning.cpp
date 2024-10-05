// tag: backtrack 回溯 dfs
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    int l = 0, r = s.size() - 1;
    while (l <= r)
    {
        if (s[l] != s[r])
            return false;
        ++l;
        --r;
    }
    return true;
}
/**
 * @brief dfs 的遍历流程为 从sub中选择0到i的子串，判断是不是子串，是就存入，不是就将问题缩减
 * 即
 * dfs(i, sub)->dfs(i, sub(0,i-1)),dfs(i, sub(i,n))
 * 边界条件为i==n
 * @param s
 * @return vector<vector<string>>
 */
vector<vector<string>> partition(string s)
{
    int n = s.size();
    vector<vector<string>> ans;
    vector<string> path;
    auto dfs = [&](auto &&dfs, int i)
    {
        if (i == n)
        {
            ans.emplace_back(path);
            return;
        }
        int start = i;
        // 遍历所有剩余子串
        while (i < n)
        {
            string sub = s.substr(start, i - start + 1);
            if (isPalindrome(sub)) // 当前串为回文串，才回继续递归
            {
                path.emplace_back(sub);
                dfs(dfs, i + 1);
                path.pop_back(); // 递归完成回溯
            }
            ++i;
        }
        return;
    };
    dfs(dfs, 0);
    return ans;
}

int main()
{
    string str;
    cin >> str;
    auto ans = partition(str);
    for (auto vs : ans)
    {
        for (auto s : vs)
        {
            cout << s << ' ';
        }
        cout << endl;
    }
}