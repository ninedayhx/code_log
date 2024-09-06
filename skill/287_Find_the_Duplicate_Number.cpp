// tag: 环形链表 快慢指针 二分查找
// 题目中说了给定的数组长度是n+1 且 数组内元素为1-n,所以可以利用这个特性
// 构建联通图，节点i指向节点nums[i]，这样就构成了一个链表，如果有多个节点
// i1, i2, i3 其值相等，即指向同一个元素，说明所构成的链表形成了至少一个环
// 那么这个问题就转化为了环形链表2问题
#include <bits/stdc++.h>

using namespace std;

int findDuplicate(vector<int> &nums)
{
    int slow = 0, fast = 0;
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    slow = 0;
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main()
{
}