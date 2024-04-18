#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>

/**
 *
 * 输入示例
50 10
b a 1 5
a * 0 2
b a 0 3
c a 1 3
d a 0 1
a * 1 2
d a 1 3
e b 0 2
f b 1 1
g c 1 2
 */

using namespace std;

struct Node {
	string name;
	Node *parent;
	int severeIssues;
	int generalIssues;
	unordered_set<Node *> children;

	Node(string nodeName) : name(nodeName), parent(nullptr), severeIssues(0), generalIssues(0) {}
};

// 辅助函数，用于构建树
void buildTree(const string &parentName, const string &childName, unordered_map<string, Node *> &nodes) {
	if (nodes.find(parentName) == nodes.end()) {
		nodes[parentName] = new Node(parentName);
	}
	if (nodes.find(childName) == nodes.end()) {
		nodes[childName] = new Node(childName);
	}
	Node *parentNode = nodes[parentName];
	Node *childNode = nodes[childName];
	childNode->parent = parentNode;
	parentNode->children.insert(childNode);
}

/**
 * 层序遍历，计算各个服务器节点值
 * @param node
 * @return
 */
int calculateDI(Node *node) {
	int gene = 0, seve = 0;
	queue<Node *> q;
	q.push(node);
	while (!q.empty()) {
		int size = q.size();
		vector<string> vs;
		for (int i = 0; i < size; i++) {
			Node *tmp = q.front();
			q.pop();
			gene += tmp->generalIssues;
			seve += tmp->severeIssues;
			for (auto n: tmp->children) {
				q.push(n);
			}
		}
	}
	int DI = 2*gene +5*seve;
	return DI;
}

int main() {
	int M, N;
	cin >> M >> N;

	unordered_map<string, Node *> nodes;
	unordered_set<Node *> roots;

	for (int i = 0; i < N; ++i) {
		string Ai, Bi, level;
		int Di;
		cin >> Ai >> Bi >> level >> Di;

		if (Bi == "*") {
			roots.insert(nodes[Ai]);
		} else {
			buildTree(Bi, Ai, nodes);
		}

		// 因为各个结构中存的都是指针，所以在这里修改对应的值，
		// 多叉树里的值也会对应改变
		if (level == "0") {
			nodes[Ai]->severeIssues += Di;
		} else if (level == "1") {
			nodes[Ai]->generalIssues += Di;
		}
	}

	cout << " tree number: " << roots.size() << endl;
	cout << endl;

	int cnt = 0;
	for (Node *root: roots) {
		int di = calculateDI(root);
		cout<<root->name<<" DI: "<<di<<endl;
		if ( di>= M) {
			cnt++;
		}
	}

	// 输出风险云服务的数量，这里可以根据具体需求调整
	cout << "Number of risk services: " << cnt << endl;

	// 释放树内存
	for (auto &pair: nodes) {
		delete pair.second;
	}

	return 0;
}