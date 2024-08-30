// tag:
#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    // 将数组第一个初始化为最大值
    int pre = 0, maxAns = nums[0];
    for (auto &i : nums)
    {
        // 如果加的值是得整个值大了，那么就记录下来
        pre = max(pre + i, i);
        maxAns = max(maxAns, pre);
    }
    return maxAns;
}

int main()
{
    vector<int> num;
    while (1)
    {
        int x;
        cin >> x;
        num.push_back(x);
        if (cin.get() == '\n')
            break;
    }
    cout << maxSubArray(num) << endl;
}