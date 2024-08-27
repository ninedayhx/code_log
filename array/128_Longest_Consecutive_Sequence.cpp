// tag:
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int maxlen = 0, len = 0;
        int tmp = INT32_MAX;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] - 1 == tmp)
                ++len;
            else if (nums[i] == tmp)
            {
                // 处理重复元素
            }
            else
            {
                maxlen = max(maxlen, len + 1);
                len = 0;
            }
            if (i == nums.size() - 1)
            {
                maxlen = max(maxlen, len + 1);
            }
            tmp = nums[i];
        }
        return maxlen;
    }
};

int main()
{
    vector<int> n = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    Solution s;
    cout << s.longestConsecutive(n);
}