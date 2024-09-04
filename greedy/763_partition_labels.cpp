// tag: greedy 贪心算法
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // 找出所有的字符的的第一个出现的和最后一个出现的位置，然后将其进行合并，
    // 合并后的区间即是满足题意的，但是区间划分一定是从头开始的，而且第一个区
    // 间的结尾是第二个区间的开头，所以不需要维护所有的起始位置，而是直接维护
    // 每一个字符的最后出现的位置即可，
    // 流程为 1.遍历一遍字符串，获得所有字符的最后出现的位置 2.遍历一遍字符串
    // ，将字符串最后的位置进行合并，如何合并呢，end变量每次都贪婪的选择比自己
    // 大的当前遍历字符的右边界，如果如果某一时刻遍历索引等于end变量说明合并结
    // 束了,然后就更新下一区间起始位置，然后继续进行合并
    vector<int> partitionLabels(string s)
    {
        vector<int> charEnd(26, 0);
        // 记录字符串中所有字符的最后出现的位置，
        for (int i = 0; i < s.size(); ++i)
        {
            charEnd[s[i] - 'a'] = i;
        }
        // 再一次遍历合并区间
        int start = 0, end = 0;
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i)
        {
            end = max(end, charEnd[s[i] - 'a']);
            if (end == i) //  当前区间合并完毕
            {
                ans.emplace_back(end - start + 1);
                start = i + 1; // 更新下一个区间的起点
            }
        }
        return ans;
    }
};

int main()
{
    string str;
    cin >> str;
    Solution s;
    auto res = s.partitionLabels(str);
    for (auto &i : res)
    {
        cout << i << ' ';
    }
    cout << endl;
}