// tag: heap map
#include <bits/stdc++.h>

using namespace std;

struct cmp
{
    // 第一个值为目标值，第二个值为输入值，输入值小于目标值为真，说明排序顺序是
    // 从大到小，也就是说小的值优先，所以定义的是小顶堆
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second >= b.second;
    }
};

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    for (auto &i : nums)
    {
        ++map[i];
    }
    // map存到vec里然后排序
    // vector<pair<int, int>> vec;
    // for (auto &m : map)
    // {
    //     vec.emplace_back(m.first, m.second);
    // }
    // sort(vec.begin(), vec.end(), cmp);
    // vector<int> res;
    // for (int i = 0; i < k; ++i)
    // {
    //     res.emplace_back(vec[i].first);
    // }
    // return res;
    // 使用堆进行优化，定义小顶堆
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> less_heap;
    for (auto &[n, f] : map)
    {
        if (less_heap.size() < k)
        {
            less_heap.emplace(n, f);
        }
        else
        {
            if (f >= less_heap.top().second)
            {
                less_heap.pop();
                less_heap.emplace(n, f);
            }
        }
    }
    vector<int> res;
    while (!less_heap.empty())
    {
        res.emplace_back(less_heap.top().first);
        less_heap.pop();
    }
    return res;
}

int main()
{
    int k;
    cin >> k;
    vector<int> n;
    while (1)
    {
        int x;
        cin >> x;
        n.emplace_back(x);
        if (cin.get() == '\n')
            break;
    }
    auto res = topKFrequent(n, k);
    for (auto &i : res)
    {
        cout << i << ' ';
    }
    cout << endl;
}