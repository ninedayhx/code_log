/***
 * n叉树的最大深度
 * 主要就是学习一下，多叉树的数据结构，在华子的题里有涉及到，如果不会构建这种数据结构
 * 可能会比较难做
 */
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

class Node {
public:
	int val;
	vector<Node *> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node *> _children) {
		val = _val;
		children = _children;
	}
};


/**
 * 构建多叉树的函数,层序遍历,输入字符串1 # 2 3 4 # 5 # 6 # 7 # (#可替换为null或*)
 * 构建                                 1
 * 									/   |   \
 * 									2   3   4
 * 									|   |   |
 * 									5   6   7
 * @param in
 * @return
 */
Node *buildNtree(string in) {
	if (in.empty()) return nullptr;
	istringstream ss(in);
	string str;
	queue<string> qs;
	while (ss >> str) {
		qs.push(str);
	}
	Node *root = new Node(stoi(qs.front()));
	qs.pop();
	qs.pop();
	queue<Node *> q;
	q.push(root);
	while (!qs.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			vector<Node *> subtree;
			while (1) {
				if (qs.front() == "null"||qs.front() == "#"|| qs.front() == "*") {
					qs.pop();
					break;
				} else {
					Node *tmp = new Node(stoi(qs.front()));
					qs.pop();
					subtree.push_back(tmp);
					q.push(tmp);
				}
			}
			q.front()->children = subtree;
			q.pop();
		}
	}
	return root;
}

/**
 * 层序打印多叉树
 * @param root
 */
void printNtree(Node *root) {
	if (!root) cout << "none" << endl;
	queue<Node *> q;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			Node * tmp = q.front();
			q.pop();
			cout<<tmp->val<<' ';
			for(auto & n:tmp->children){
				q.push(n);
			}
		}
		cout<<endl;
	}
}


int recursion(Node *root) {
	if (!root) return 0;
	vector<int> vdep;
	for (auto &n: root->children) {
		vdep.push_back(recursion(n));
	}
	if (vdep.empty()) return 1;  //无法对空向量使用max_element,所以在此判定
	return 1 + *max_element(vdep.begin(), vdep.end()); // 最后再加上本节点的长度1
}

/**
 * 多叉树的最大深度，与二叉树的最大深度一致
 * @param root
 * @return
 */
int maxDepth_Nrytree(Node *root) {
	return recursion(root);
}

int main() {
	// 不仅仅要会使用Ntree，还要学会构建Ntree
	vector<string> in;
	string s;
	getline(cin, s);
	Node *root = buildNtree(s);
	printNtree(root);
	cout << maxDepth_Nrytree(root);

}