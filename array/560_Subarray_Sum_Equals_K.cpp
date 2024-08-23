// tag: array 前缀表
// 滴滴提前批1面
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // 暴力解法会超时 时间复杂度o(n2) 空间复杂度 o(1)
    int subarraySum(vector<int> &nums, int k)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j)
            {
                sum += nums[j];
                if (sum == k)
                    ++ans;
            }
        }
        return ans;
    }
    int subarraySum_map(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        map[0] = 1;
        int ans = 0, presum = 0;
        for (auto &i : nums)
        {
            presum += i;
            if (map.find(presum - k) != map.end())
                ans += map[presum - k];
            ++map[presum];
        }
        return ans;
    }
};

int main()
{
    vector<int> nums;
    int i;
    while (1)
    {
        cin >> i;
        nums.push_back(i);
        if (cin.get() == '\n')
            break;
    }
    for (auto i : nums)
        cout << i << ' ';
    cout << endl;
    cin >> i;
    Solution s;
    cout << s.subarraySum(nums, i);
    cout << '\n';
    cout << s.subarraySum_map(nums, i);
}