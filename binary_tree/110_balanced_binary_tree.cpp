/**
 * 给定一个二叉树，判断其是否为平衡二叉树
 * 平衡二叉树的定义为，所有节点的左右子树的高度差的绝对值不超过1
 */
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
	TreeNode *left;
	TreeNode *right;
	int val;

	TreeNode() : val(0), left(nullptr), right(nullptr) {};

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};

	TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(nullptr), right(nullptr) {};
};

/**
 * 层序递归创建，主要是知道每个节点对应的子树位置，第i个节点的子树在i*2+1和i*2+2处
 * @param nums
 * @param i
 * @return
 */
TreeNode *levelOrderCreate_recursion(vector<string> &nums, int i) {
	if (nums[i] == "#" || nums[i] == "null" || i >= nums.size()) return nullptr;
	TreeNode *cur = new TreeNode(stoi(nums[i]));
	cur->left = levelOrderCreate_recursion(nums, i * 2 + 1);
	cur->right = levelOrderCreate_recursion(nums, i * 2 + 2);
	return cur;
}

/**
 * 层序迭代创建
 * @return
 */
TreeNode *levelOrderCreate_iterate(vector<string> &nums) {
	if (nums.empty() || nums[0] == "#" || nums[0] == "null") return nullptr;
	TreeNode *root = new TreeNode(stoi(nums[0]));
	int i = 1;
	queue<TreeNode *> q;
	q.push(root);
	while (i < nums.size() && !q.empty()) {
		TreeNode *cur = q.front();
		q.pop();
		if (nums[i] != "#" || nums[i] != "null") {
			cur->left = new TreeNode(stoi(nums[i]));
			q.push(cur->left);
		}
		i++;
		if (nums[i] != "#" || nums[i] != "null") {
			cur->right = new TreeNode(stoi(nums[i]));
			q.push(cur->right);
		}
		i++;
	}
	return root;
}

vector<int> levelOrderTraval(TreeNode *root) {
	if (!root) return {};
	queue<TreeNode *> q;
	vector<int> res;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		TreeNode *cur = q.front();
		q.pop();
		res.push_back(cur->val);
		for (int i = 0; i < size; i++) {
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}
	}
	return res;
}

int getDepth(TreeNode *cur) {
	if (!cur) return 0;
	queue<TreeNode *> q;
	q.push(cur);
	int cnt;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			// 一次性处理一个层，所以每一层计一个数
			TreeNode *tmp = q.front();
			q.pop();
			if (!tmp->left) q.push(tmp->left);
			if (!tmp->right) q.push(tmp->right);
		}
		cnt++;
	}
	return cnt;
}

bool isBalanced(TreeNode *root) {
	bool flag = true;
	if (!root) return flag;
	queue<TreeNode *> q;
	q.push(root);
	while (!q.empty()) {
		int size = q.size();
		TreeNode *cur = q.front();
		q.pop();
		if (abs(getDepth(cur->left) - getDepth(cur->right)) > 1) flag = false;
		for (int i = 0; i < size; i++) {
			if (cur->left) q.push(cur->left);
			if (cur->right) q.push(cur->right);
		}
	}
	return flag;
}

int main() {
	string s;
	vector<string> vs;
	while (cin >> s) {
		vs.push_back(s);
		if (cin.get() == '\n') break;
	}
	TreeNode *root1 = levelOrderCreate_recursion(vs, 0);
	TreeNode *root2 = levelOrderCreate_iterate(vs);

	vector<int> res = levelOrderTraval(root1);
	for (int i: res) {
		cout << i << ' ';
	}
	cout << endl;

	res = levelOrderTraval(root2);
	for (int i: res) {
		cout << i << ' ';
	}
	cout << endl;
	cout << endl;
	cout << isBalanced(root1);

}
