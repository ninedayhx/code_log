#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * 朴素dijkstra算法，使用邻接矩阵，时间复杂度O(n^2)
 * @param times
 * @param n
 * @param k
 * @return
 */
int networkDelayTime_dijkstra_adjmat_simple(vector<vector<int>> &times, int n, int k) {
	// 该矩阵的所有初始权重设置为无穷大，除以二是为了保证inf+inf操作时不会溢出
	const int inf = INT_MAX / 2;
	// 定义邻接矩阵
	vector<vector<int>> g(n, vector<int>(n, inf));
	// 遍历延迟矩阵，将延迟矩阵转化为邻接矩阵
	for (auto &t: times) g[t[0] - 1][t[1] - 1] = t[2];

	// 用于动态的记录和更新起点到各个节点的最小距离
	vector<int> dist(n, inf);
	dist[k - 1] = 0;  // 指定起点到起点的距离为0

	// 记录节点是否被访问过
	vector<bool> visited(n);

	for (int i = 0; i < n; i++) {
		int x = -1;  //记录起点集合S中的候选起点
		for (int y = 0; y < n; y++) {
			// 如果第一次进入循环，即x=-1;且y没有被访问过，就以其作为集合候选起点
			// 如果没有被访问过，且起点到y的距离小于起点到x的距离，则更新y为新的集合候选起点
			// 所以在这次迭代中，x到候选
			if (!visited[y] && (x == -1 || dist[y] < dist[x])) x = y;
		}
		// 更新访问标志
		visited[x] = true;
		// 遍历所有节点
		for (int y = 0; y < n; y++) {
			//如果经由候选起点x到y的距离小于从起点到y的距离，就以此作为新的距离值进行更新
			dist[y] = min(dist[y], g[x][y] + dist[x]);
		}
	}
	// dist中存储的是起点到各个节点的最短距离，
	// 假设从起点发射一个信号，信号同时进行传递，传输距离最远的那个节点就是本次传输中的最大延迟
	int ans = *max_element(dist.begin(), dist.end());
	// 如果最大延迟为inf,则说明有节点无法联通，所以返回-1
	return ans == inf ? -1 : ans;

}

int networkDelayTime_dijkstra_adjtable_priority_queue(vector<vector<int>> &times, int n, int k) {
	// 为何初始化为这个值，是因为后面会有inf+inf的操作，如果直接设置为INT_MAX,
	// 计算时会导致加法溢出
	// 也有一些人喜欢写为0x3f3f3f3f，因为这是一个较大的值，在以前的代码上进行memset会比较方便
	// 其实只要选取一个较大的值作为无穷大就行，这个值需要满足无穷大的性质，
	// 即inf+const =inf, inf+inf =inf
	// 如果取整形最大值INT_MAX,就不满足这个性质，因为 INT_MAX+INT_MAX会溢出，也就不是最大值了
	const int inf = INT_MAX / 2;
	// 构建邻接表
	vector<vector<pair<int, int>>> g(n);
	// 遍历延迟矩阵，将延迟矩阵转化为邻接表,这里的存储方式和之前略有不同
	// pair中第一个存id, 第二个存距离
	for (auto &t: times) {
		g[t[0] - 1].emplace_back(t[1] - 1, t[2]);
	}
	// 用于更新起点到其他各个节点的最短距离
	vector<int> dist(n, inf);
	// 起点到起点的距离为0，初始时起点到其他节点的距离全设为无穷大
	dist[k - 1] = 0;
	// 使用一个优先队列作为小根堆，或者叫小顶堆，greater，说明队列的顶端top最小
	// 下面这个定义表示，队列内的元素是 pair<int,int> 队列的所使用的容器是vector，排序方式是从小到大greater
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	// 因为优先队列的存储元素为pair,则排序的时候默认以pair的第一个元素作为排序的对象
	// 所以pair的第1个元素为距离，第二个元素为节点号
	// 下面这个表示把节点k到自己的距离设置为0
	// 也就是把起始节点入集合
	// 这个队列其实就是dijkstras中的集合S
	pq.emplace(0, k - 1);

	while (!pq.empty()) {
		// 取距离起点集合S最近的点，优先队列特性
		auto [time, x] = pq.top();
		pq.pop();
		// 用于判定是否访问过，如果访问过，就跳过
		if (dist[x] < time) continue;
		// g[x]中存储的是x节点到其他节点的距离
		// 这里等于遍历获取起点集合S到其他节点距离
		for (auto &e: g[x]) {
			// 其他节点的id使用y进行遍历
			int y = e.first;
			// 这里表示经由x节点到y节点的距离
			int d = dist[x] + e.second;
			if (d < dist[y]) {
				dist[y] = d;
				pq.emplace(d, y);
			}
		}
	}
	int ans = *max_element(dist.begin(), dist.end());
	return ans == inf ? -1 : ans;
}

int main() {
	int n, k, edges;
	cin >> n >> k >> edges;
	vector<vector<int>> times;
	for (int i = 0; i < edges; i++) {
		int u, v, w;
		vector<int> time;
		cin >> u >> v >> w;
		times.push_back({u, v, w});
	}
	for (auto &v: times) {
		for (auto &t: v) {
			cout << t << ' ';
		}
		cout << endl;
	}
	cout << networkDelayTime_dijkstra_adjmat_simple(times, n, k);
	cout << networkDelayTime_dijkstra_adjtable_priority_queue(times, n, k);
}
