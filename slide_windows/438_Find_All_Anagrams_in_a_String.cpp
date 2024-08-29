// tag: slide_window hashtable
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
};

/**
 * @brief 暴力解法，并没有用到滑动窗口的特性
 *
 * @param s
 * @param p
 * @return vector<int>
 */
vector<int> findAnagrams(string s, string p)
{
    int psize = p.size();
    sort(p.begin(), p.end());
    vector<int> ans;
    for (int i = 0; i < s.size() - p.size() + 1; ++i)
    {
        auto sub = s.substr(i, p.size());
        sort(sub.begin(), sub.end());
        if (sub == p)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

/**
 * @brief 使用作为一维数组作为hash表,数组的id 0-25 即表示字符 a-z
 *        对应的值就是字符的数量
 *
 * @param s
 * @param p
 * @return vector<int>
 */
vector<int> findAnagrams2(string s, string p)
{
    vector<int> hash(26, 0), tmp(26, 0);
    vector<int> ans;
    if (s.size() < p.size())
        return {};
    for (int i = 0; i < p.size(); ++i)
    {
        ++hash[s[i] - 'a'];
        ++tmp[p[i] - 'a'];
    }
    if (tmp == hash)
        ans.emplace_back(0);
    for (int i = 0; i < s.size() - p.size(); ++i)
    {
        --hash[s[i] - 'a'];
        ++hash[s[i + p.size()] - 'a'];
        if (hash == tmp)
        {
            ans.emplace_back(i + 1);
        }
    }
    return ans;
}

int main()
{
    string src, tar;
    cin >> src;
    cin >> tar;
    auto res = findAnagrams(src, tar);
    for (auto &i : res)
    {
        cout << i << ' ';
    }
    cout << endl;

    auto res = findAnagrams(src, tar);
    for (auto &i : res)
    {
        cout << i << ' ';
    }
    cout << endl;
}