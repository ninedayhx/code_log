// tag: array
#include <bits/stdc++.h>

using namespace std;

struct cmp
{
    bool operator()(vector<int> a, vector<int> b)
    {
        if (a[0] < b[0])
            return true;
        else if (a[0] == b[0])
        {
            return b[1] >= a[1];
        }
        else
        {
            return false;
        }
    }
};

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    int l = intervals[0][0], r = intervals[0][1];
    for (int i = 1; i < n; ++i)
    {
        if (intervals[i - 1][1] >= intervals[i][0])
        {
            l = intervals[i - 1][0];
            r = max(intervals[i - 1][1], intervals[i][1]);
        }
        else
        {
            vector<int> tmp = {l, r};
            ans.emplace_back(tmp);
            l = intervals[i][0];
            r = max(intervals[i - 1][1], intervals[i][1]);
        }
    }
    vector<int> tmp = {l, r};
    ans.emplace_back(tmp);
    return ans;
}

int main()
{
    vector<vector<int>> intervals = {{1, 4}, {0, 2}, {3, 5}};
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; ++i)
    // {
    //     int l, r;
    //     cin >> l >> r;
    //     intervals.emplace_back(l, r);
    // }
    auto ans = merge(intervals);
    for (auto &v : ans)
    {
        cout << v[0] << ", " << v[1] << endl;
    }
}