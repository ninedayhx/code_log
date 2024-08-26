// tag:slide_windows string array
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    /**
     * @brief 这里等于是暴力解法，遍历每一个子串，
     *        但要注意到在上一次遍历完不含重复元素的子串时，左边界移动以后
     *        剩下的子串也不包含重复元素，所以可以保留上一次的右边界，这样就不用每次都从左边界开始找了
     *
     * @param s
     * @return int
     */
    int lengthOfLongestSubstring1(string s)
    {
        int maxsub = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            int r = i;
            unordered_set<char> set;
            while (r < s.size())
            {
                if (set.find(s[r]) != set.end())
                {
                    maxsub = max(maxsub, (int)set.size());
                }
                set.insert(s[r]);
                ++r;
            }
        }
        return maxsub;
    }
    int lengthOfLongestSubstring2(string s)
    {
        int res = 0;
        // 记录不重复的子串
        unordered_set<char> set;
        // 右边界
        int j = 0;
        // 滑动左边界
        for (int i = 0; i < s.size(); ++i)
        {
            // 每次窗口移动后，去除不应该在窗口中的元素
            if (i)
            {
                set.erase(s[i - 1]);
            }
            // 滑动右窗口，检查当前窗口中是否有重复元素，有则记录长度，跳过
            while (j < s.size() && !set.count(s[j]))
            {
                set.insert(s[j]);
                ++j;
            }
            // 每一次滑动后的右边界都继承到下一次，因为左边界更新后的窗口中，
            // 不会存在重复元素，这样就避免了无效的遍历
            // res = max(res, (int)set.size());
            // 窗口长度就是不重复子串的长度
            res = max(res, j - i);
        }
        return res;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    cout << s.lengthOfLongestSubstring2(str);
}