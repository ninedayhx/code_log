// tag: greedy 贪心算法 array
#include <bits/stdc++.h>

using namespace std;

bool canJump_greedy(vector<int> &nums)
{
    int maxlen = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        // 如果在最远到达的范围内
        if (i <= maxlen)
        {
            // 每一个位置最远能到达的位置是
            // 当前位置 + 当前位置能跳的距离
            // 但是之前的最远到达的位置，可能比当前最大位置大
            // 所以取二者中大的那个
            maxlen = max(maxlen, i + nums[i]);
            if (maxlen >= nums.size() - 1)
                return true;
        }
    }
    return false;
}

int main()
{
    vector<int> nums;
    while (1)
    {
        int x;
        cin >> x;
        nums.emplace_back(x);
        if (cin.get() == '\n')
            break;
    }
    cout << canJump_greedy(nums) << endl;
}