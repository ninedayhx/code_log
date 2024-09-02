// tag: greedy
#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int cost = INT_MAX;
    int maxprof = 0;
    for (auto &p : prices)
    {
        cost = min(cost, p);
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