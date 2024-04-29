/**
 * 深度优先搜索，递归版和迭代版
 * 广度优先搜索，递归版和迭代版
 */
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

/**
 * leetcode 官方题解递归做法
 */
class solution1 {
public:
	vector<vector<int>> ans;
	// 使用向量作为栈，进行记录走的路径和回溯
	vector<int> vst;
	// 使用stack也是一样的,
	// 但是使用stack,还需要会导致顺序错乱
	// 所以还是使用vector最好
	// stack<int> st;

	void DFS(vector<vector<int>> &g, int cur) {
		int n = g.size() - 1;
		if (cur == n) { // 找到了终点
			ans.push_back(vst);
			return;
		}
		// 对当前节点进行深度探索，
		for (auto &y: g[cur]) {
			vst.push_back(y);
			DFS(g, y);
			vst.pop_back();
			// 去掉尾部元素进行回溯，因为每次递归都会回溯，所以回溯一步就行
		}
	}

	vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
		//  本题中，输入是以邻接表的形式存储，可以不用转成邻接矩阵
		vst.push_back(0);
		DFS(graph, 0);
		return ans;
	}
};

/**
 * 深度优先搜索，迭代做法
 */
class solution2 {
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
		int destination = graph.size() - 1;
		vector<vector<int>> ans;
		vector<int> path;
		vector<int> stack;

		stack.push_back(0);
		while (!stack.empty()) {
			int cur = stack.back(); // 当前访问路径点
			path.push_back(cur);

			if (cur == destination) ans.push_back(path);

			// 将当前节点的全部子节点入栈
			for (int i = 0; i < graph[cur].size(); ++i) {
				stack.push_back(graph[cur][i]);
			}

			// path.back() == stack.back() 表示到达了路径的尽头
			// 不管尽头是终点还是不是终点， 此时要进行回溯操作，
			// 回溯就是把路径恢复到与stack不一致的那个时刻
			// 也就是同时回退，直到末端不相同
			while (!path.empty() && path.back() == stack.back()) {
				path.pop_back(); // 离开时刻：首次离开path的back节点
				stack.pop_back();
			}
		}
		return ans;
	}
};


int main() {
	solution2 s2;
	int n, m;
	cin >> n >> m;
	if(cin.get()=='\n');
	vector<vector<int>> graph(n);
	for (int i = 0; i < n; i++) {
		vector<int> v;
		string str;
		getline(cin,str);
		if(str == "\n") {
			v.emplace({});
		}else{
			istringstream ss(str);
			string i;
			while(ss>>i){
				v.push_back(stoi(i));
			}
		}
		graph[i] = v;
	}
	for (auto &v: graph) {
		for (auto &i: v) {
			cout << i << ' ';
		}
		cout << endl;
	}
	vector<vector<int>> res = s2.allPathsSourceTarget(graph);
	for (auto &v: res) {
		for (auto &i: v) cout << i << ' ';
		cout << endl;
	}
	cout << endl;
}