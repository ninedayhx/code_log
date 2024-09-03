// tag: greedy
#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int cost = INT_MAX;
    int maxprof = 0;
    for (auto &p : prices)
    {
        // 动态的维护最小代价
        cost = min(cost, p);
        // 计算当前最小代价下的最大利益
        maxprof = max(maxprof, p - cost);
    }
    return maxprof;
}

int main()
{
    vector<int> prices;
    while (1)
    {
        int x;
        cin >> x;
        prices.emplace_back(x);
        if (cin.get() == '\n')
            break;
    }
    cout << maxProfit(prices) << endl;
}