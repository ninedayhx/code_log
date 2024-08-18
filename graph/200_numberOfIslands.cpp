#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {

        return 0;
    }
    static void printVec2D(vector<vector<char>> vec)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            for (int j = 0; j < vec[i].size(); j++)
            {
                cout << vec[i][j] << ' ';
            }
            cout << "\n";
        }
    }
};

int main()
{
    // input n: size of graph
    // then n rows input
    int n;
    cin >> n;
    vector<vector<char>> graph(n);
    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            char tmp;
            cin >> tmp;
            graph[i].emplace_back(tmp);
            if (cin.get() == '\n')
                break;
        }
    }
    Solution::printVec2D(graph);

    Solution solver;
    cout << solver.numIslands(graph);
}
