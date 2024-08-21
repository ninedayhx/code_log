// tag :array matrix
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<pair<int, int>> mark;
    void cleanrow(vector<vector<int>> &matrix, int row)
    {
        for (int i = 0; i < matrix[0].size(); i++)
        {
            matrix[row][i] = 0;
        }
    }
    void cleancol(vector<vector<int>> &matrix, int col)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            matrix[i][col] = 0;
        }
    }

public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    mark.push_back({i, j});
                }
            }
        }
        for (auto p : mark)
        {
            cleanrow(matrix, p.first);
            cleancol(matrix, p.second);
        }
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
    vector<vector<int>> mat;
    int x = 0, n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        vector<int> vec;
        while (1)
        {
            cin >> x;
            vec.push_back(x);
            if (cin.get() == '\n')
                break;
        }
        mat.push_back(vec);
    }
    printf("\n");
    printMat(mat);
    printf("\n");
    Solution solver;
    solver.setZeroes(mat);
    printMat(mat);
}