#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int inf = INT_MAX / 2;

vector<int> dijkstra(vector<vector<int>> &g, int k) {
	int n = g.size();
	vector<int> dist(n, inf);
	vector<bool> visited(n);
	dist[k] = 0;
	for (int i = 0; i < n; i++) {
		int x = -1;
		for (int y = 0; y < n; y++) {
			if (!visited[y] && (x == -1 || dist[y] < dist[x])) x = y;
		}
		visited[x] = true;
		for (int y = 0; y < n; y++) {
			dist[y] = min(dist[y], g[x][y] + dist[x]);
		}
	}
	dist[k] = inf;
	return dist;
}

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
	vector<vector<int>> g(n, vector<int>(n, inf));
	for (auto &v: edges) {
		// 无向图，所以对称赋值
		g[v[0]][v[1]] = v[2];
		g[v[1]][v[0]] = v[2];
	}
	vector<vector<int>> dists;
	for (int i = 0; i < n; i++) {
		vector<int> dist = dijkstra(g, i);
		dists.push_back(dist);
	}
	// 初始化时距离要取最大，更新时会出问题
	pair<int,int> ans = {inf,-1};
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++){
			if(dists[i][j]<=distanceThreshold) cnt++;
		}
		// 更新最小值
		// 这里一定要小于等于，这样就能保证两个城市一样多时，取id大的那个
		if(cnt<=ans.first) ans = {cnt, i};
	}
	return ans.second;
}

int main() {
	int n, edgenum, threshold;
	cin >> n >> edgenum >> threshold;
	vector<vector<int>> edges;
	for (int i = 0; i < edgenum; i++) {
		int e;
		vector<int> ve;
		while (cin >> e) {
			ve.push_back(e);
			if (cin.get() == '\n') break;
		}
		edges.push_back(ve);
	}
	cout << findTheCity(n, edges, threshold);
}