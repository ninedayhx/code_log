// tag: double_pointer dual_pointer
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i)
        {
            // 固定i，双指针左右遍历, 此时target即为nums[i]
            // 退化为有序数组的2sum,如果target>0显然总值不会小于0,则直接退出循环
            if (nums[i] > 0)
                break;
            // 处理重复元素
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // 双指针
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                if (nums[j] + nums[k] == -nums[i])
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    // 如果重复，就继续找到不重复的为止
                    while (j < k && nums[j] == nums[j - 1])
                        ++j;
                    --k;
                    while (j < k && nums[k] == nums[k + 1])
                        --k;
                }
                if (nums[j] + nums[k] < -nums[i])
                {
                    ++j;
                    while (j < k && nums[j] == nums[j - 1])
                        ++j;
                }
                if (nums[j] + nums[k] > -nums[i])
                {
                    --k;
                    while (j < k && nums[k] == nums[k + 1])
                        --k;
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> n = {-1, 0, 1, 2, -1, -4};
    // while (1)
    // {
    //     int x;
    //     cin >> x;
    //     n.push_back(x);
    //     if (cin.get() == '\n')
    //         break;
    // }
    Solution s;
    auto res = s.threeSum(n);
    for (auto &v : res)
    {
        for (auto &i : v)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
}