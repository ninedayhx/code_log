// tag: skill XOR 异或 位运算
#include <bits/stdc++.h>

using namespace std;

int singleNumber(vector<int> &nums)
{
    // 利用异或的性质，自己和自己异或等于0
    // a与0异或等于a
    // 所以如果把nums里的所有值互相进行异或，
    // 结果就是那个只有一个的元素
    // c++异或操作为 ^
    int ret = 0;
    for (auto &i : nums)
    {
        ret ^= i;
    }
    return ret;
}

int main()
{
    vector<int> nums;
    while (1)
    {
        int x;
        cin >> x;
        nums.push_back(x);
        if (cin.get() == '\n')
            break;
    }
    cout << singleNumber(nums);
}