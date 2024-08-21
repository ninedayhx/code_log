// tag: array slide_windows queue
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 自定义比较函数
// 使用结构体，重载operator()操作符
struct cmp
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.first > b.first;
    }
};

class Solution
{
public:
    vector<int>
    maxSlidingWindow(vector<int> &nums, int k)
    {
        // 大顶堆
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> big_heap;
        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            // 存储值以及对应id，id用于判断其是否在窗口内
            big_heap.push({nums[i], i});
        }
        res.push_back(big_heap.top().first);
        for (int i = k; i < nums.size(); i++)
        {
            big_heap.push({nums[i], i});
            while (big_heap.top().second < i - k)
            {
                big_heap.pop();
            }
            res.push_back(big_heap.top().first);
        }
        return res;
    }
};

int main()
{
}