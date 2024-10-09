// tag: 回溯，dfs , backtrack
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief 从board每一个点出发去dfs找，每找一个方向如果不是就回溯
 * dfs的入口参数 i，j 表示board起点
 * idx 表示word的索引
 * 边界条件为idx=word.size()-1 则返回成功
 *         如果各个方向都找了，无结果，就返回失败
 * 同时需要使用标记数组表示已访问的元素，然后对标记数组进行回溯即可
 * @param board
 * @param word
 * @return true
 * @return false
 */
bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size(), n = board[0].size();
    if (m * n < word.size())
    {
        return false;
    }
    vector<int> vx = {-1, 1, 0, 0};
    vector<int> vy = {0, 0, -1, 1};
    bool ans = false;
    vector<vector<int>> vis(m, vector<int>(n, 0));
    auto dfs = [&](auto &&dfs, int i, int j, int idx)
    {
        if (board[i][j] == word[idx])
        {
            if (idx == word.size() - 1)
            {
                ans = true;
                return;
            }
            vis[i][j] = 1;
            for (int k = 0; k < 4; ++k)
            {
                int x = i + vx[k], y = j + vy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y])
                {
                    dfs(dfs, x, y, idx + 1);
                }
            }
            vis[i][j] = 0; // 回溯
        }
        return;
    };
    for (int a = 0; a < m; ++a)
    {
        for (int b = 0; b < n; ++b)
        {
            dfs(dfs, a, b, 0);
        }
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> board(m);
    for (int i = 0; i < m; ++i)
    {
        string str;
        cin >> str;
        for (auto &ch : str)
        {
            board[i].emplace_back(ch);
        }
    }
    string word;
    cin >> word;
    cout << exist(board, word);
}