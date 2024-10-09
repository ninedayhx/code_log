// tag: dp 动态规划
#include <bits/stdc++.h>

using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.size();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<int> dp(n + 1);
    dp[0] = 1;
    for (int right = 1; right <= n; ++right)
    {
        for (int left = 0; left < right; ++left)
        {
            // substr 第一个参数是子字符串的起点，第二个参数是子字符串的长度
            string sub = s.substr(left, right - left);
            if (dp[left] == 1 && dict.count(sub) == 1)
            {
                // right 始终指向子字符串的下一个字符
                // left 始终指向子字符串的初始idx
                dp[right] = 1;
            }
        }
    }
    return dp[n];
}

int main()
{
    string str;
    cin >> str;
    int n;
    cin >> n;
    vector<string> worddict(n);
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> worddict[i];
    }
    cout << wordBreak(str, worddict);
}