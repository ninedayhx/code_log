// tag: hashtable
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // 同分异构词，如果对其进行排序后，结果一定一样，所以
    // 可以使用字典顺序作为hash表的键，然后判定两个词是否为同分
    // 异构词
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> map;
        for (auto &s : strs)
        {
            string key = s;
            sort(key.begin(), key.end());
            map[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto &i : map)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main()
{
    vector<string> ss;
    int n;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        ss.push_back(s);
    }
    Solution solu;
    auto res = solu.groupAnagrams(ss);
    for (auto &vs : res)
    {
        for (auto str : vs)
        {
            cout << str << ' ';
        }
        cout << endl;
    }
}