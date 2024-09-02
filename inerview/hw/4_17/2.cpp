/**
 * 云服务问题数量
 *
 * 我们将云服务看做一棵树，每个云服务在发布前尚来解决的问题称为云服务的遗留问题
 * (云服务的遗留问题包合以该云服务为根节点的树上所有节点的问题)，
 * DI值(遗留问题缺陷密度)可以作为评估云服务发布的指标，
 * 当云服务DI值小于等于阈值时才准许云服务发布，否则视为风险云服务，需要问题整改完成后重新进行发布
 *
 * 现有一批云服务树，已给出云服务树各节点的问题数量，请通过计算输出风险云服务的个数。
 * 计算公式:DI值<5x严重问题数+2x一般问题数，
 * 其中每个节点的不同级别问题数量需要将该节点及该节点为根节点的所有子节点的相应级别问题数量求和。
 *
 * 输入
 * 第1行输入 M 和 N(M  100000，N<1000 )，使用空格分隔，
 * 		M 表示代表云服务阈值，
 * 		N 表示接下来有 N 行问题统计数据
 * 接下来输入一个 N*4 的矩阵表，行内使用空格分隔，
 * 		第一列 Ai 为服务节点，
 * 		第二列 Bi 为 Ai 的父节点，如果 Ai 为云服务则无父节点此时 Bi 用 *号表示
 * 		( Ai 和 Bi取值为字符串，1 < 字符串长度 <5,均由小写英文字母或 * 号组成)，
 * 		第三列Ci 为问题级别( Ci取值为(0,1}，0表示严重问题，1表示一般问题)
 * 		第四列 Di 为该节点该级别的问题数量( Di< 1000 )。
 * 说明:输入保证只出现树的关系，不会出现连通图的情况。
 *
 * 输出 风险云服务个数
 *
 * eg:
 * input:
 * 			50 10
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
 * output:  2
 *
 */

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