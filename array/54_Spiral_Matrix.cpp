// tag: array
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // 定义上下左右四个界限，界限在循环中不断迭代
        int upper = 0;
        int down = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        vector<int> res;
        while (1)
        {
            // 向右遍历，
            for (int i = left; i <= right; ++i)
                res.push_back(matrix[upper][i]);
            // 第一层遍历完成，所以上界更新
            // 如果上界超过下界，则退出
            if (++upper > down)
                break;
            // 向下遍历
            for (int i = upper; i <= down; ++i)
                res.push_back(matrix[i][right]);
            if (--right < left)
                break;
            // 向左遍历
            for (int i = right; i >= left; --i)
                res.push_back(matrix[down][i]);
            if (--down < upper)
                break;
            // 向上遍历
            for (int i = down; i >= upper; --i)
                res.push_back(matrix[i][left]);
            if (++left > right)
                break;
        }
        return res;
    }
};
void printMat(const vector<vector<int>> &matrix)
{
    for (auto &v : matrix)
    {
        for (auto &i : v)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
}

int main()
{
    int m;
    vector<vector<int>> mat;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        vector<int> res;
        while (1)
        {
            int x;
            scanf("%d", &x);
            res.push_back(x);
            if (cin.get() == '\n')
                break;
        }
        mat.push_back(res);
    }
    printMat(mat);
    Solution solver;
    auto res = solver.spiralOrder(mat);
    for (auto i : res)
    {
        cout << i << ' ';
    }
    cout << '\n';
}