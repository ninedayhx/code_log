// tag:
#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>> g, int m, int k)
{
    int influ = 0;
    queue<int> q;
    q.push(m);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        --k;
        for (int &i : g[cur])
        {
            q.push(i);
            ++influ;
        }
        if (k == 0)
        {
            return influ;
        }
    }
    return influ;
}

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> graph(1001);
    for (int i = 0; i < N; ++i)
    {
        int X, Y;
        cin >> X >> Y;
        // 直接存储双向id，实现类似于邻接表
        graph[X].emplace_back(Y);
        graph[Y].emplace_back(X);
    }
    cout << bfs(graph, M, K) << endl;
}