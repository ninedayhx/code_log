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
    // sort(intervals.begin(), intervals.end(), cmp());
    sort(intervals.begin(), intervals.end());

    if (intervals.size() == 1)
    {
        return intervals;
    }
    vector<int> first(2, 0);
    first = intervals[0];
    vector<vector<int>> res;
    for (int i = 1; i < intervals.size(); ++i)
    {
        if (first[1] >= intervals[i][0])
        {
            first[0] = min(first[0], intervals[i][0]);
            first[1] = max(first[1], intervals[i][1]);
        }
        else
        {
            res.emplace_back(first);
            first = intervals[i];
        }
    }
    res.emplace_back(first);
    return res;
}

int main()
{
    vector<vector<int>> intervals;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int l, r;
        cin >> l >> r;
        intervals.emplace_back(l, r);
    }
    auto merge(intervals);
    for (auto &v : intervals)
    {
        cout << v[0] << v[1] << endl;
    }
}