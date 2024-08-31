// tag: graph 多源bfs
#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<int> mx = {-1, 1, 0, 0};
    vector<int> my = {0, 0, -1, 1};

public:
    /**
     * @brief 多源广度优先搜索迭代版，本质上和广度优先搜索迭代版是一致的
     *        只不过起点是多个的
     * @param grid
     * @return int
     */
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0; // 新鲜的个数
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    ++fresh; // 统计新鲜橘子
                }
                else if (grid[i][j] == 2)
                {
                    // 把腐烂的橘子的位置入队列
                    q.push({i, j});
                }
            }
        }
        int ans = -1; // 当前时间设为-1分钟
        // 类似于广度优先搜索的迭代实现，
        // 但是一开始队列中就有多个源头，也就是说多源广度优先
        while (!q.empty())
        {
            // 每进去一层，时间加
            ++ans;
            int size = q.size();
            for (int i = 0; i < size; ++i) // 遍历已经腐烂的橘子
            {
                auto [x, y] = q.front();
                q.pop();
                // 依次进行广度遍历
                for (int i = 0; i < 4; ++i)
                {
                    int a = x + mx[i];
                    int b = y + my[i];
                    // 只找新鲜的
                    if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == 1)
                    {
                        --fresh;
                        grid[a][b] = 2;
                        q.push({a, b});
                    }
                }
            }
        }
        return fresh ? -1 : max(ans, 0);
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> g;

    for (int i = 0; i < m; ++i)
    {
        vector<int> vec;
        while (1)
        {
            int x;
            cin >> x;
            vec.push_back(x);
        }
        g.push_back(vec);
    }

    Solution s;
    cout << s.orangesRotting(g);
}