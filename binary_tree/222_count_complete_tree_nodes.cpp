

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

	/**
	 * 222 计算完全二叉树的深度
	 */
	/**
	 * 按照遍历的方式去做，层序遍历，但题目要求是对于完全二叉树而言的，
	 * 所以需要利用完全二叉树的性质
	 * @param root
	 * @return
	 */
	int countNodes_regular(TreeNode *root) {
		if (!root) return 0;
		queue<TreeNode *> q;
		q.push(root);
		int dep = 0;
		while (!q.empty()) {
			int n = q.size();
			TreeNode *tmp = q.front();
			q.pop();
			dep++;
			for (int i = 0; i < n; i++) {
				if (!tmp->left) q.push(tmp->left);
				if (!tmp->right) q.push(tmp->right);
			}
		}
		return dep;
	}

	/**
	 * 使用完全二叉树的性质，必须要知道完全二叉树的性质
	 * 完全二叉树 的定义如下：
	 * 在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
	 * 并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则
	 * 该层包含 1~ 2h 个节点。
	 *
	 * 如果是满二叉树，则节点数量就是2^h-1个，
	 * 所以可以分别对子树进行满二叉树判定，然后递归遍历不是满二叉树的子树
	 *
	 * 那么就可以先进行深度搜索，一直向左子树搜索，直到左子树的终点，然后再
	 * @param root
	 * @return
	 */
	int countNodes_complete_tree(TreeNode *root) {
		if (!root) return 0;
		int leftnum = 0, rightnum = 0;
		TreeNode *left = root->left, *right = root->right;
		// 一直向下遍历左子树，统计左子树的深度
		while (left) {
			left = left->left;
			leftnum++;
		}
		// 统计右子树的深度
		while (right) {
			right = right->right;
			rightnum++;
		}
		// 如果左子树深度等于右子树深度，说明当前节点是一颗满二叉树
		// 依据满二叉树的深度即可直接求解出当前节点的所有子节点的数量
		// 2^h-1
		if (leftnum == rightnum) {
			return (2 << leftnum) - 1; // 位运算更快
		}
		// 如果左子树深度不等于右子树深度，则说明当前节点不是满二叉树
		// 就需要进一步的分别对左右子树进行递归递归
		// 其中加一表示加上当前root节点
		return countNodes_complete_tree(root->left) + countNodes_complete_tree(root->right) + 1;
	}

};


int main() {
	Solution solver;
	string str, s;
	getline(cin, str);
	TreeNode *root = solver.preorderCreate(str);
	cout << solver.countNodes_complete_tree(root);
}