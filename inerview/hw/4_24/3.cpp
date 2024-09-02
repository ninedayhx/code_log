/**
 * hw 0424 找到内聚值最大的微服务群组
 * 微服务使用0~n-1数字进行编号，给定一个下标从0开始的数组 edges[i],
 * 其中edges[i]表示一条从微服务i到微服务edges[i]的接口调用
 *
 * 我们将形成一个环的多个微服务称为微服务群组，一个微服务群组的所有微服务数量为L,
 * 能够访问到该微服务群组的微服务数量为V,该群组的内聚值 H = L-V
 *
 * 已知提供的数据中右一个或多个群组，请按照从大到小对所有群组的内聚值H进行排序，H相等时
 * 取群组中最大数进行比较，输出排在第一的微服务群组，输出时，每个微服务群组的输出的起始编号
 * 为环中最小的数
 *
 * 输入第一个行为微服务数量
 * 第二行为edges[i], edges[i]表示存在一条从i到edges[i]的微服务调用
 *
 * eg1
 * input:  4
 * 		   3 3 0 2
 * output: 0 3 2
 *
 * eg2
 * input:  12
 * 		   2 6 10 1 6 0 3 0 5 4 5 8
 *
 * output: 0 2 10 5
 */
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

vector<int> path;
vector<int> visited;

void DFS(vector<int> &g, int id) {
	for (auto &i: path) {
		if (id == i) {
			return;
		}
	}
	path.push_back(id);
	DFS(g, g[id]);
}

void findbestloop(vector<int> &g, int n) {
	vector<vector<int>> paths(n);
	int size = INT_MAX;
	vector<int> tmp;
	for (int i = 0; i < n; i++){
		DFS(g, i);
		if(size>=path.size()){
			tmp = path;
			size = path.size();
		}
	}
}


int main() {
	int n;
	cin >> n;
	int x;
	vector<int> graph(n);
	for (int i = 0; i < n; i++) {
		cin >> x;
		graph[i] = x;
	}

}