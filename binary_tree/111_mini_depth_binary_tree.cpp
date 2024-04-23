
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
		maxDepthRes = maxDepthRes > depth ? maxDepthRes : depth;    // 访问中
		if (root->left) {                                            // 访问左
			depth++;
			preRecursion(root->left, depth); // 继续递归，把当前值传递
			depth--;                         // 深度回溯，假装自己没有访问过左子树，以保证访问右子树时，深度不会累加
		}
		if (root->right) {                                            // 访问右
			depth++;
			preRecursion(root->right, depth);
			depth--;
		}
		return;
	}

	int maxDepth_preRecursion(TreeNode *root) {
		maxDepthRes = 0;
		if (!root) return 0;
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

	/**
	 * 这是错误的写法，在这种情况下，没有左子树，或者没有右子树的节点深度将作为最小深度eg
	 * 										1
	 * 									   / \
	 * 									  2   3
	 * 									 /     \
	 *                                  4       5
	 * 这种情况下，用如下错误算法求出来的，最小深度将会是1，而实际上最小深度应该是2
	 *
	 * @param depth
	 * @return
	 */
	int min_recursion_err(TreeNode *cur, int depth) {
		if (!cur) return 0;
		int left_depth = min_recursion_err(cur->left, depth);
		int right_depth = min_recursion_err(cur->right, depth);
		return 1 + left_depth < right_depth ? left_depth : right_depth;
	}

	/**
	 * 后序遍历求最小深度
	 * @param cur
	 * @param depth
	 * @return
	 */
	int min_recursion(TreeNode *cur, int depth) {
		if (!cur) return 0;
		if ((!cur->left) && cur->right) {
			return 1+ min_recursion(cur->right, depth);
		} else if ((!cur->right) && cur->left) {
			return 1+min_recursion(cur->left, depth);
		}else{
			return 1+min(min_recursion(cur->right, depth), min_recursion(cur->left, depth));
		}
	}

	int minDepth_recursion(TreeNode *root) {
		int res;
		//res = min_recursion_err(TreeNode * root, 0);
		res = min_recursion(root, 0);
		return res;
	}

	/**
	 * 层序遍历迭代法求最小深度
	 * @param root
	 * @return
	 */
	int minDepth_iterate(TreeNode *root) {
		if(!root) return 0;
		int dep = 0;
		queue<TreeNode *> q;
		q.push(root);
		dep++;
		while(!q.empty()){
			int size  = q.size();
			for(int i =0;i<size;i++){
				TreeNode * tmp = q.front();
				q.pop();
				if(tmp->left) q.push(tmp->left);
				if(tmp->right) q.push(tmp->right);
				// 只要遇到了第一个左右子树都为空，就说明遇到了最短的节点
				if(!tmp->right&&!tmp->left){
					return dep;
				}
			}
		}
		return dep;
	}


};


int main() {
	Solution solver;
	string str, s;
	getline(cin, str);
	TreeNode *root = solver.preorderCreate(str);
	cout << solver.minDepth_recursion(root)<<endl;
	cout<<solver.minDepth_iterate(root)<<endl;
}