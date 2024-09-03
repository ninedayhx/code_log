// tag: array 前缀和 二维前缀和
#include <bits/stdc++.h>

using namespace std;

class NumMatrix
{
private:
    vector<vector<int>> prevSum;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        prevSum.resize(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int up = 0, left = 0, repeat = 0;
                if (i > 0)
                    up = prevSum[i - 1][j];
                if (j > 0)
                    left = prevSum[i][j - 1];
                if (i > 0 && j > 0)
                    repeat = prevSum[i - 1][j - 1];
                prevSum[i][j] = left + up - repeat + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return prevSum[row2][col2] - prevSum[row2][col1 - 1] - prevSum[row1 - 1][col2] + prevSum[row1 - 1][col1 - 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix;
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
        matrix.emplace_back(v);
    }
    NumMatrix nm(matrix);
    int k;
    cin >> k;
    vector<vector<int>> query(k, vector<int>(4));
    for (int i = 0; i < k; ++i)
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
        query.emplace_back(v);
    }
    for (int i = 0; i < k; ++i)
    {
        cout << nm.sumRegion(query[i][0], query[i][1],
                             query[i][2], query[i][3]);
        cout << endl;
    }
}