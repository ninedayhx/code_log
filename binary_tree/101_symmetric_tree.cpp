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

	/**
	 * 101 判断是否为对称的树
	 * @param root
	 * @return
	 */
	bool isSymmetric(TreeNode* root) {
		if(root== nullptr) return true;
		TreeNode *l = root->left, *r = root->right;
		queue<TreeNode *> q;
		q.push(l);
		q.push(r);
		while(!q.empty()){
			// 成对出队列
			l = q.front();q.pop();
			r = q.front();q.pop();
			// 如果都是空节点
			if(!l&&!r) continue;
			// 如果有一个是空节点，或者是两个不是空节点，但内容不同，返回false
			if((!l||!r)||l->val!=r->val) return false;
			// 两侧节点的子树对称入队列
			q.push(l->left);
			q.push(r->right);

			q.push(l->right);
			q.push(r->left);
		}
		return true;
	}
};


int main() {
	Solution solver;
	string str, s;
	getline(cin, str);
	TreeNode *root = solver.preorderCreate(str);
	cout<<solver.isSymmetric(root);
}