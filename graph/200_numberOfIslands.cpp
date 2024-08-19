#include <iostream>
#include <vector>
#include <chrono>
#include <stack>
#include <queue>

using namespace std;

class Solution
{
private:
    vector<vector<char>> tmp;

public:
    chrono::microseconds duration;

private:
    // 深度优先搜索，会修改原矩阵，
    void dfs(vector<vector<char>> &g, int i, int j)
    {
        if ((i < 0 || i >= g.size()) || (j < 0 || j >= g[i].size()))
            return;
        if (g[i][j] == '0')
            return;
        if (g[i][j] == '1')
            g[i][j] = '0';

        dfs(g, i - 1, j);
        dfs(g, i + 1, j);
        dfs(g, i, j - 1);
        dfs(g, i, j + 1);
    }

    void bfs()
    {
    }

public:
    int numIslands_dfs_change(vector<vector<char>> &grid)
    {
        tmp = grid;
        auto start = chrono::high_resolution_clock::now();
        int islandNums = 0;
        for (int i = 0; i < tmp.size(); i++)
        {
            for (int j = 0; j < tmp[i].size(); j++)
            {
                if (tmp[i][j] == '1')
                {
                    ++islandNums;
                    dfs(tmp, i, j);
                }
            }
        }
        auto end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
        return islandNums;
    }

    /**
     * @brief 队列进行广度优先搜索，初始点入队列，然后队列广度的循环条件为
     *        while(!q.empty()){
     *
     *        }
     *
     * @param grid
     * @return int
     */
    int numIslands_bfs(vector<vector<char>> &grid)
    {
        auto start = chrono::high_resolution_clock::now();
        int islandNums = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[i].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++islandNums;
                    grid[i][j] = '0';
                    q.push({i, j});
                    while (!q.empty())
                    {
                        auto [row, col] = q.front();
                        q.pop();
                        if (row - 1 >= 0 && grid[row - 1][col] == '1')
                        {
                            q.push({row - 1, col});
                            grid[row - 1][col] = '0';
                        }
                        if (row + 1 < grid.size() && grid[row + 1][col] == '1')
                        {
                            q.push({row + 1, col});
                            grid[row + 1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col - 1] == '1')
                        {
                            q.push({row, col - 1});
                            grid[row][col - 1] = '0';
                        }
                        if (col + 1 >= 0 && grid[row][col + 1] == '1')
                        {
                            q.push({row, col + 1});
                            grid[row][col + 1] = '0';
                        }
                    }
                }
            }
        }

        auto end = chrono::high_resolution_clock::now();
        duration = chrono::duration_cast<std::chrono::microseconds>(end - start);
        return islandNums;
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
    cout << "dfs_change: " << solver.numIslands_dfs_change(graph)
         << " cost us: " << solver.duration.count() << endl;
    cout << "bfs_change: " << solver.numIslands_bfs(graph)
         << " cost us: " << solver.duration.count() << endl;
}
