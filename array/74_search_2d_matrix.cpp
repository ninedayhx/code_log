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
    int n = matrix[0].size();
    if (m == 0 || target < matrix[0][0] || target > matrix[m - 1][n - 1])
        return false;
    // 找对应行的过程也可变为二分查找
    // for (int i = 0; i < m; ++i)
    // {
    //     if (i < m - 1 && target >= matrix[i][0] && target < matrix[i + 1][0])
    //     {
    //         return binarySearch(matrix[i], target);
    //     }
    //     if (i == m - 1 && target >= matrix[i][0])
    //     {
    //         return binarySearch(matrix[i], target);
    //     }
    // }
    int up = 0, down = m - 1;
    int mid = 0;
    while (up <= down)
    {
        mid = (up + down) / 2;
        if (target >= matrix[mid][0])
        {
            if (mid + 1 <= m - 1 && target < matrix[mid + 1][0])
            {
                return binarySearch(matrix[mid], target);
            }
            if (mid == m - 1)
            {
                return binarySearch(matrix[mid], target);
            }
            if (target >= matrix[mid + 1][0])
            {
                up = mid + 1;
            }
        }
        if (target < matrix[mid][0])
        {
            down = mid - 1;
        }
    }

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