// tag:
// 小美初始位于(a,b)位置，一维平面上有n 个瓶子，每个瓶子的位置为(xi,yi)，
// 小美每次可以向上、下、左、石移动一格，每次移动的代价为1，小美需要每次移动
// 到一个瓶子的位置上，然后拿起瓶子把它放到(c,d)位置，每次最多只能拿一个瓶子
// 。请问最少需要多少代价才能把所有瓶子都放到(c,d)位置上。
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, y, a, b, c, d;
    long long cost_all = 0;
    cin >> a >> b >> c >> d;
    cin >> n;
    vector<pair<int, int>> bottle;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        bottle.push_back({x, y});
    }
    pair<int, int> min_cost_start = {INT32_MAX, -1};
    for (int i = 0; i < n; i++)
    {

        int cost = abs(bottle[i].first - a) + abs(bottle[i].second - b) +
                   abs(bottle[i].first - c) + abs(bottle[i].second - d);
        if (cost <= min_cost_start.first)
        {
            min_cost_start.first = cost;
            min_cost_start.second = i;
        }
    }
    cost_all += min_cost_start.first;
    for (int i = 0; i < n; i++)
    {
        if (i != min_cost_start.second)
        {
            cost_all += 2 * (abs(bottle[i].first - c) + abs(bottle[i].second - d));
        }
    }
    cout << cost_all << endl;
}