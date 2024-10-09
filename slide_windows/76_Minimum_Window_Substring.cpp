// tag: array string 滑动窗口
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size())
            return "";
        if (s == t)
            return s;
        int l = 0, r = 0;
        string minSub = s + '0';
        unordered_map<char, int> map_t;
        for (auto ch : t)
        {
            map_t[ch]++;
        }
        for (l = 0; l < s.size(); ++l)
        {
            unordered_map<char, int> tmp = map_t;
            int len = t.size();
            for (r = l; r < s.size(); ++r)
            {
                if (tmp.find(s[r]) != tmp.end() && tmp[s[r]] > 0)
                {
                    tmp[s[r]]--;
                    len--;
                }
                if (len == 0)
                {
                    if (minSub.size() >= r - l + 1)
                    {
                        minSub = s.substr(l, r - l + 1);
                    }
                    break;
                }
            }
        }
        return minSub == s + '0' ? "" : minSub;
    }
};

int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    Solution solver;
    cout << solver.minWindow(s, t);
}