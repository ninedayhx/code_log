#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>

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

	void inTraversal(TreeNode *root, vector<int> &vec) {
		if (root == nullptr) return;
		inTraversal(root->left, vec);
		vec.push_back(root->val);
		inTraversal(root->right, vec);

	}

	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> res;
		inTraversal(root, res);
		return res;
	}

	/**
	 * 迭代法进行中序遍历，主要是要模拟出递归法中出栈入栈过程，
	 * 模拟过程和后序遍历差不多
	 * @param root
	 * @return
	 */
	vector<int> inorderTraversal_iterate(TreeNode *root) {
		stack<TreeNode *> st;
		vector<int> res;
		if (root == nullptr) return res;
		while (root != nullptr || !st.empty()) {
			// 循环迭代到当前分支最下面那个左子树，
			// 并将中间遇到的节点入栈，以便后续重新访问
			while (root != nullptr) {
				st.push(root);
				root = root->left;
			}
			root = st.top();
			st.pop();
			// 如果右子树为空，则说明当前节点是左子树或右子树的终点，计入结果
			// 但一般而言，都是左子树先被遍历到，在是右子树被遍历到
			if (root->right == nullptr) {
				res.push_back(root->val);
				root = nullptr;
			} else {
				// 如果不为空，说明是根节点，计入结果，由于先是左子树被遍历然后计入结果
				// 然后根节点计入结果，然后是右子树被遍历计入结果
				// 所以是中序遍历
				res.push_back(root->val);
				root = root->right;
			}
		}
		return res;
	}

};


int main() {
	Solution solver;
	string str, s;
	getline(cin, str);
	TreeNode *root = solver.preorderCreate(str);
	vector<int> res = solver.inorderTraversal(root);
	for (auto &i: res) {
		cout << i << ' ';
	}
	cout << endl;

	res = solver.inorderTraversal_iterate(root);
	for (auto &i: res) {
		cout << i << ' ';
	}
	cout << endl;
}