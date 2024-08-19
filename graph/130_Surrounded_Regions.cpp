// tag:DFS;BFS;array;graph;
#include <iostream>
#include <vector>
#include <queue>

// 抓住重点，如果某一个点在矩阵的边界上，就说明该点所处的那块不会被包围，
// 所以可以从边界上的o点进行搜索，将与边界o点的交界处的其他o点标记为其他，
// 那么最后只需要再遍历一次，就可以完成

using namespace std;

class Solution
{
private:
    int m, n;
    vector<int8_t> mapx = {-1, 1, 0, 0};
    vector<int8_t> mapy = {0, 0, -1, 1};

private:
    void dfs(vector<vector<char>> &g, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || g[i][j] != 'O')
        {
            return;
        }
        if (g[i][j] == 'O')
            g[i][j] = 'F';
        for (int k = 0; k < 4; k++)
        {
            dfs(g, i + mapx[k], j + mapy[k]);
        }
    }

    void update(vector<vector<char>> &g)
    {
        for (auto &v : g)
        {
            for (auto &ch : v)
            {
                if (ch == 'O')
                    ch = 'X';
                if (ch == 'F')
                    ch = 'O';
            }
        }
    }

public:
    /**
     * @brief 从边开始深度优先搜索
     *
     * @param board
     */
    void solve_dfs_edge(vector<vector<char>> &board)
    {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 从矩阵的边开始遍历
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O')
                {
                    dfs(board, i, j);
                }
            }
        }
        update(board);
    }
    /**
     * @brief 广度优先搜索，但是抓住题目的特性，从边界开始找
     *
     * @param board
     */
    void solve_bfs_edge(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // 从矩阵的边开始遍历
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && board[i][j] == 'O')
                {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    board[i][j] = 'F';
                    while (!q.empty())
                    {
                        auto idx = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++)
                        {
                            int x = idx.first + mapx[k];
                            int y = idx.second + mapy[k];
                            if ((x >= 0 && x < m) && (y >= 0 && y < n) && board[x][y] == 'O')
                            {
                                q.push({x, y});
                                board[x][y] = 'F';
                            }
                        }
                    }
                }
            }
        }
        for (auto &v : board)
        {
            for (auto &ch : v)
            {
                if (ch == 'O')
                    ch = 'X';
                if (ch == 'F')
                    ch = 'O';
            }
        }
    }
    // 此方法暴力广度搜索每一个点，然后使用一个visited矩阵判断是否访问过
    // 广搜的过程中,如果出现了某一个点的邻接越界，则说明该范围不完全被包围，然后就保留
    void solve_bfs(vector<vector<char>> &board)
    {
        vector<vector<int>> vistied(board.size(), vector<int>(board[0].size()));
        for (auto &v : vistied)
        {
            for (auto &i : v)
            {
                i = 0;
            }
        }
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[i][j] == 'O' && !vistied[i][j])
                {
                    queue<pair<int, int>> q;
                    vector<pair<int, int>> res;
                    int flag = 0;
                    q.push({i, j});
                    vistied[i][j] = 1;
                    while (!q.empty())
                    {
                        auto [m, n] = q.front();
                        res.push_back({m, n});
                        q.pop();
                        if ((m - 1 < 0 || m + 1 >= board.size()) || (n - 1 < 0 || n + 1 >= board[0].size()))
                        {
                            flag = 1;
                        }
                        vector<int> vx = {m - 1, m + 1, m, m};
                        vector<int> vy = {n, n, n - 1, n + 1};
                        for (int k = 0; k < 4; ++k)
                        {
                            int x = vx[k],
                                y = vy[k];
                            if ((x >= 0 && x < board.size()) && (y >= 0 && y < board[0].size()) && board[x][y] == 'O' && !vistied[x][y])
                            {
                                q.push({x, y});
                                res.push_back({x, y});
                                vistied[x][y] = 1;
                            }
                        }
                    }
                    if (!flag)
                    {
                        for (const auto p : res)
                        {
                            board[p.first][p.second] = 'X';
                        }
                    }
                }
            }
        }
    }
    template <typename T>
    static void printVec2D(vector<vector<T>> vec)
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
    int n;
    cin >> n;
    vector<vector<char>> board(n);
    for (int i = 0; i < n; i++)
    {
        while (1)
        {
            char ch;
            cin >> ch;
            board[i].emplace_back(ch);
            if (cin.get() == '\n')
                break;
        }
    }
    cout << endl;
    Solution::printVec2D(board);
    cout << endl;
    Solution solver;
    solver.solve_bfs_edge(board);
    Solution::printVec2D(board);
}