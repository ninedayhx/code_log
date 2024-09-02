// tag: binary_search 二分查找
#include <bits/stdc++.h>

using namespace std;

bool binarySearch(vector<int> vec, int t)
{
    int left = 0, right = vec.size() - 1;
    int mid = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (t == vec[mid])
        {
            return true;
        }
        if (t > vec[mid])
        {
            left = mid + 1;
        }
        if (t < vec[mid])
        {
            right = mid - 1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size();
    int up = 0, down = m - 1;
    int ans = -1;
    while (up <= down)
    {
        int mid = (up + down) >> 1;
        if (target >= matrix[mid][0])
        {
            ans = mid;
            up = mid + 1;
        }
        else
        {
            down = mid - 1;
        }
    }
    if (ans >= 0)
        return binary_search(matrix[ans].begin(), matrix[ans].end(), target);
    else
        return false;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> g;
    for (int i = 0; i < m; ++i)
    {
        vector<int> v;
        while (1)
        {
            int x;
            cin >> x;
            v.emplace_back(x);
            if (cin.get() == '\n')
                break;
        }
        g.emplace_back(v);
    }
    int t;
    cin >> t;
    cout << searchMatrix(g, t) << endl;
}