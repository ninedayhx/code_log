// tag: backtrack 回溯 dfs 子集型回溯
#include <bits/stdc++.h>

using namespace std;

vector<string> letterCombinations(string digits)
{
    unordered_map<char, string> keymap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};
    vector<string> ans;
    int n = digits.size();
    if (n == 0)
        return ans;
    string path(n, '0');
    auto dfs = [&](auto &&dfs, int i)
    {
        if (i == n)
        {
            ans.emplace_back(path);
            return;
        }
        for (auto &ch : keymap[digits[i]])
        {
            // 因为是直接赋值的，新的dfs时，会覆盖原来的值，等于隐式的回溯了，
            path[i] = ch;
            dfs(dfs, i + 1);
            // 所以无需进行回溯操作
            // path[i] = '0';
            // path.pop_back();
        }
    };
    dfs(dfs, 0);
    return ans;
}

int main()
{
    string input;
    cin >> input;
    auto ans = letterCombinations(input);
    for (auto &str : ans)
    {
        cout << str << ' ';
    }
}