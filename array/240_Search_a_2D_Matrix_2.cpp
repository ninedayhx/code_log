// tag:
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief z字查找 从右上或者从左下找都行，适合矩阵行列均有序的情况，
 *        从对角线两端进行查找
 *        是因为整个可以抽象为一个二叉搜索树，右上节点的左边比其小，
 *        而下面节点比其大，也就构成了一个二叉搜索树
 *        时间复杂度 O(m+n)
 * @param matrix
 * @param target
 * @return true
 * @return false
 */
bool searchMatrix_zsearch(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();
    int i = 0, j = n - 1;
    while (i < m && j >= 0)
    {
        if (matrix[i][j] == target)
        {
            return true;
        }
        if (matrix[i][j] > target)
        {
            --i;
        }
        if (matrix[i][j] < target)
        {
            ++j;
        }
    }
}

/**
 * @brief 二分查找， 对每行或者每列进行二分查找 复杂度 o(mlogn) 或 o(nlogm)
 * @param matrix
 * @param target
 * @return true
 * @return false
 */
bool searchMatrix_binarySearch(vector<vector<int>> &matrix, int target)
{
    int m = matrix.size(), n = matrix[0].size();
    // 行大于列，对列进行二分找
    if (m > n)
    {
        for (int j = 0; j < n; ++j)
        {
            int up = 0, down = m - 1;
            while (up <= down)
            {
                int mid = (up + down) >> 1;
                if (matrix[mid][j] == target)
                {
                    return true;
                }
                else if (matrix[mid][j] > target)
                {
                    down = mid - 1;
                }
                else if (matrix[mid][j] < target)
                {
                    up = mid + 1;
                }
            }
        }
        return false;
    }
    else
    {
        for (int i = 0; i < m; ++i)
        {
            int left = 0, right = n - 1;
            while (left <= right)
            {
                int mid = (left + right) >> 1;
                if (matrix[i][mid] == target)
                {
                    return true;
                }
                else if (matrix[i][mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return false;
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat;
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
        mat.emplace_back(v);
    }
    int t;
    cin >> t;
    cout << searchMatrix_zsearch(mat, t);
}