// tag:
#include <bits/stdc++.h>

using namespace std;

// 多数元素的长度超过数组长度的一般，所以一定出现在数组中间
int majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

int main()
{
}