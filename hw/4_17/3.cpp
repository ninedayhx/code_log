#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int inf = INT_MAX / 2;

/**
 * 朴素dijkstra,
 * @param adjmat 邻接矩阵
 * @param k      起点
 * @return
 */
vector<int> dijkstra(vector<vector<int>> &g, int k) {
	int n = g.size();
	vector<int> dist(n, inf);
	dist[k] = 0;
	vector<bool> visited(n);
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

vector<int> findEscapePath(vector<vector<int>> &delaymat,
						   vector<int> &cap, int id, int n) {
	vector<int> mindist = dijkstra(delaymat, id);

	for (auto &d: mindist) {
		cout << d << ' ';
	}
	cout << endl;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	for (int i = 0; i < mindist.size(); i++) {
		pq.emplace(mindist[i], i);
	}
	vector<int> res;
	int cnt = 0;
	for (int i = 0; i < mindist.size(); i++) {
		auto [d, idx] = pq.top();
		pq.pop();
		cnt += cap[idx];
		res.push_back(idx);
		if (cnt >= n) break;
	}
	cout << res.size() << endl;
	return res;
}

int main() {
	vector<vector<int>> delaymat;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++) {
		vector<int> v;
		int x;
		while (cin >> x) {
			if (x == -1) x = inf;
			v.push_back(x);
			if (cin.get() == '\n') break;
		}
		delaymat.push_back(v);
	}
	int n;
	vector<int> capc;
	while (cin >> n) {
		capc.push_back(n);
		if (cin.get() == '\n') break;
	}
	int faultid, casenum;
	cin >> faultid >> casenum;

	vector<int> res;
	res = findEscapePath(delaymat, capc, faultid, casenum);
	for (auto &i: res) {
		cout << i << ' ';
	}
	cout << endl;
}
