/**
 * 云上故障逃生
 *
 * 在云上多个业务节点之间选择最快的逃生节点集，并考虑每个节点的剩余业务容量。
 * 有一个网络时延表，表示每个节点到其他节点的通信延迟，
 * 还有一个剩余业务容量表，表示每个节点的剩余业多容量，
 * 在一个节点故障时，需要选择一个或多个逃生节点，确保逃生路径的时延最小，
 * 并且逃生节点集各节点剩余容量的总和足够容纳故障节点的业务量，
 * 当故障节点会多个节点最短距离相同，优先选择编号较小的节点容灾，
 * 如果逃生节点集中多个节点最短距离相同时按编号从小到大的顺序排列。
 *
 * 输入
 * 第1行n表示云上业多节点数，2<n<10000，节点编号从0开始，依次递增;
 * 第2到1+n行表示业务节点问的网络时延矩阵表 delayMatrix[i][j],
 * 		delayMatrix[i][j] 表示节点i到节点j的通信时延
 * 			1)如果节点i和节点i之间没有直接相连的边，则 delayMatrix[i][j] 为-1，
 * 			第i个节点和它自己也没有边，所以delayMatrix[i][j]=-1
 * 			2)节点间有边时时延范围为 1<= delayMatrix[i][j]<= 1000
 * 			矩阵元素间使用空格分割
 * 			输入保证 delayMatrix[i][j] == delayMatrix[j][i]
 * 第2+n行表示各业务节点的剩余容量表remainingcapacity，
 * 		其中remainingCapacity[i] 表示节点i的剩余业务容量，业务量的范围1 <= remainingCapacityi<= 100 ，
 * 		数组元素间使用空格分割:
 * 第3+n行表示故障业务节点编号 faultyNode，表示发生故障的节点，取值为0<faultyNode<n
 * 第4+n行表示受损业务节点要迁移的业务量,受损业务量的范围(0-1000]
 *
 * 输出
 * 返回符合条件的逃生路径节点编号列表(以单空格问隔)，
 * 当所有节点都不够故障节点容灾的时候，输出所有容灾节点。
 *
 * eg
 * input::	4
			-1  5 -1  8
			 5 -1  1  3
			-1  1 -1  4
			 8  3  4 -1
			10 20 15 25
			2
			12
 * output:	1
 *
 */
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
