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

	vector<int> postorderTraversal_iterate(TreeNode *root) {
		stack<TreeNode *> st;
		TreeNode *prev = nullptr; // 用于记录上一次读取的节点
		vector<int> res;
		if(root== nullptr) return res;
		// 当栈空或者是访问节点为空时，说明遍历结束
		while (!st.empty()||root!=nullptr) {
			// 首先向最左边深度搜索，直到找到最左边末端节点
			while (root != nullptr) {
				st.push(root);
				root = root->left;
			}
			root = st.top();
			st.pop();
			// 此时root将处于某一子树的最左下节点，则开始判断右子树
			if (root->right == nullptr || root->right == prev) {
				// 如果root的右子树为空，或者右子树已经访问过，则把当前结果记录下来
				res.push_back(root->val);
				prev = root;
				// root 置空，防止循环访问左子树
				// 这样下次循环时，将会向上访问父节点
				root = nullptr;
			} else {
				// 如果右子树不为空，且之前没有访问过，就把当前节点重新入栈，然后向下迭代
				st.push(root);
				// 并将root迭代 ，这样下一次循环时就会深度搜索当前节点的全部左子树
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
	vector<int> res = solver.postorderTraversal(root);
	for (auto &i: res) {
		cout << i << ' ';
	}
	cout << endl;

	res = solver.postorderTraversal_iterate(root);
	for (auto &i: res) {
		cout << i << ' ';
	}
	cout << endl;
}