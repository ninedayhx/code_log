#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode *rpreorderCreate(istringstream &ss) {

		string tmp;
		ss >> tmp;
		if (tmp == "#") {
			return nullptr;
		}
		//cout<<tmp<<endl;
		TreeNode *node = new TreeNode(stoi(tmp));
		node->left = rpreorderCreate(ss);
		node->right = rpreorderCreate(ss);
		return node;
	}

	/*
	 * 先序创建二叉树，输入的序列必须合法，eg
	 *                1
	 *               / \
	 *              2   3
	 * 表述为 1 2 # # 3 # #
	 */
	TreeNode *preorderCreate(string data) {
		istringstream ss(data);
		return rpreorderCreate(ss);
	}

	/**
	 * 使用队列进行层序遍历，但是输出为一维向量，无法记录层数
	 * @param root
	 * @return
	 */
	vector<int> levelOrderTraversal_1d(TreeNode *root) {
		queue<TreeNode *> q;
		TreeNode *tmp;
		vector<int> res;
		if (root == nullptr) return res;
		q.push(root);
		while (!q.empty()) {
			tmp = q.front();
			res.push_back(tmp->val);
			q.pop();
			if (tmp->left) q.push(tmp->left);
			if (tmp->right) q.push(tmp->right);
		}
		return res;
	}

	/**
	 * 只需要多使用一个循环即可记录层数，因为当前队列的长度就是当前层的有效节点的数量
	 * @param root
	 * @return
	 */
	vector<vector<int>> levelOrderTraversal(TreeNode *root) {
		queue<TreeNode *> q;
		TreeNode *tmp;
		vector<vector<int>> res;
		if (root == nullptr) return res;
		q.push(root);
		while (!q.empty()) {
			// 队列中的元素个数，就是当前层有效节点的个数
			// 必须要提前获取size,否则在后续的for循环中，队列的大小是动态改变的
			int size = q.size();
			vector<int> vec;
			// 把当前层的左右子树入队列
			// 把当前层的值入结果
			for (int i = 0; i < size; i++) {
				tmp = q.front();
				q.pop();
				vec.push_back(tmp->val);
				if (tmp->left) q.push(tmp->left);
				if (tmp->right) q.push(tmp->right);
			}
			res.push_back(vec);
		}
		return res;
	}

};


int main() {
	Solution solver;
	string str, s;
	getline(cin, str);
	TreeNode *root = solver.preorderCreate(str);
	vector<vector<int>> res = solver.levelOrderTraversal(root);
	for (auto &v: res) {
		for (auto &i: v) {
			cout << i << ' ';
		}
	}
	cout << endl;
}