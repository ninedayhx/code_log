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

	void pretraversal(TreeNode *cur, vector<int> &vec) {
		if (cur == nullptr) return;
		vec.push_back(cur->val);
		pretraversal(cur->left, vec);
		pretraversal(cur->right, vec);
	}

	/**
	 * 先序递归遍历二叉树
	 * @param root
	 * @return
	 */
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		pretraversal(root, result);
		return result;
	}
	/*
	 * 迭代法先序遍历，需要使用栈进行操作，为啥呢，因为根节点的左右子树就类似于括号匹配，遍历完左右子树就相当于
	 * 括号都匹配上了，循环的终止条件就是栈空
	 * 而入栈时需要先入右子树再入左子树，这样出栈时就会先左再右，符合先序遍历的情况。
	 */
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

};


int main() {
	Solution solver;
	string str, s;
	getline(cin, str);
	TreeNode *root = solver.preorderCreate(str);
	vector<int> res = solver.preorderTraversal(root);
	for (auto &i: res) {
		cout << i << ' ';
	}
	cout << endl;

	res = solver.preorderTraversal_iterate(root);
	for (auto &i: res) {
		cout << i << ' ';
	}
	cout << endl;
}