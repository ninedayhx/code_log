// tag:
#include <bits/stdc++.h>

using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, less<int>> pq;
    for (auto &i : nums)
    {
        pq.push(i);
    }
    for (int i = 0; i < k; ++i)
    {
        pq.pop();
    }
    return pq.top();
}

int main()
{
}