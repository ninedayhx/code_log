
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

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

	void postTraversal(TreeNode *root, vector<int> &vec) {
		if (root == nullptr) return;
		postTraversal(root->left, vec);
		postTraversal(root->right, vec);
		vec.push_back(root->val);
	}

	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> res;
		postTraversal(root, res);
		return res;
	}

	vector<int> preorderTraversal_iterate(TreeNode *root) {
		stack<TreeNode *> st;
		vector<int> res;
		TreeNode *tmp;
		st.push(root);
		while (!st.empty()) {
			if (st.top() == nullptr) {
				st.pop();
			} else {
				tmp = st.top();
				res.push_back(tmp->val);
				st.pop();
				st.push(tmp->right);
				st.push(tmp->left);
			}
		}
		return res;
	}

	int maxDepthRes;
	void preRecursion(TreeNode *root, int depth) { // 参数中，不能使用int & depth 否则进行回溯
		maxDepthRes = maxDepthRes > depth ? maxDepthRes : depth;  	// 访问中
		if (root->left) {										 	// 访问左
			depth++;
			preRecursion(root->left, depth); // 继续递归，把当前值传递
			depth--;					     // 深度回溯，假装自己没有访问过左子树，以保证访问右子树时，深度不会累加
		}
		if (root->right) {											// 访问右
			depth++;
			preRecursion(root->right, depth);
			depth--;
		}
		return ;
	}

	int maxDepth_preRecursion(TreeNode *root) {
		maxDepthRes = 0;
		if(!root) return 0;
		preRecursion(root, 1);
		return maxDepthRes;
	}

	/**
	 * 后序遍历访问最大深度
	 * @param root
	 * @return
	 */
	int maxDepth_postRecursion(TreeNode *root) {
		if (root == nullptr) return 0;
		int leftdepth = maxDepth_postRecursion(root->left);   // 访问左
		int rightdepth = maxDepth_postRecursion(root->right); // 访问右
		return 1 + max(leftdepth, rightdepth);    // 访问中
	}


	/**
	 * 层序遍历确定其最大深度，通过迭代的方式
	 * @param root
	 * @return
	 */
	int maxDepth_level_iterate(TreeNode *root) {
		int maxD = 0;
		queue<TreeNode *> q;
		if (root == nullptr) return maxD;
		q.push(root);
		TreeNode *tmp;
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				tmp = q.front();
				q.pop();
				if (tmp->left) q.push(tmp->left);
				if (tmp->right) q.push(tmp->right);
			}
			maxD++;
		}
		return maxD;
	}
};


int main() {
	Solution solver;
	string str, s;
	getline(cin, str);
	TreeNode *root = solver.preorderCreate(str);
	cout << solver.maxDepth_level_iterate(root);
}