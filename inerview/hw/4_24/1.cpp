/**1. 满二叉搜索树查找
 * 题目描述：给定2^n-1个不同的整数，构建一颗平衡满二叉搜索树，然后
 * 输入一个待查找的数字，输出查找的路径和结果
 * 二叉搜索树的定义为：
 * 1. 节点的左子树只包含小于当前节点的数
 * 2. 节点的右子树只包含大于当前节点的数
 * 3. 所哟与左子树和右子树自身必须也是二叉搜索树，
 *
 * 如数字序列为 1-7，则构建的满二叉搜索树如下
 * 					4
 * 				   /  \
 * 				  2    6
 * 				 / \  / \
 *              1  3  5  7
 * 输入第一行为 2^n-1 个不同整数，以空格隔开，用于构建二叉搜索树
 * 输入第二行为 带查找的数字
 * 输出查找路径和结果
 * eg1:
 * input: 2 1 3 7 5 6 4
 *        6
 * output: SRY
 *
 * eg2:
 * input: 1 2 3 4 5 6 7
 * 		  8
 * output: SRRN
 */

// 解析： 题目中要求构建一颗平衡满二叉搜索树，其实是一个陷阱，只需要把输入序列排个序就行
// 然后依据排序的序列进行二叉树搜索，如果真想构建一颗二叉树，会比较困难

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <algorithm>

using namespace std;

struct node {
	node *left;
	node *right;
	int val;
};

//错误的做法，先建树然后再查找
class solution {
public:
	void buildTree(node *root, vector<int> &in) {
		int n = in.size() / 2;
		root->left = new node();
		root->right = new node();
		for (int i = 0; i < n; i++) {

		}
	}

	string findnode(node *root, int tag) {
		string res;

		return res;
	}
};

// 正确的做法，直接将输入数组排序，然后进行二分查找
// 二分查找的路径就是二叉搜索树的路径
// 二分查找 区间设置为左闭右闭
class solution2 {
public:
	string findNodePath(vector<int> &input, int target) {
		string res;
		int left = 0, right = input.size() - 1;
		sort(input.begin(), input.end());
		res += 'S';
		while (left < right) {
			int mid = (left + right) / 2;
			if (input[mid] > target) {
				right = mid - 1;
				res += 'L';
			} else if (input[mid] < target) {
				left = mid + 1;
				res += 'R';
			} else if (input[mid] == target) {
				res += 'Y';
				return res;
			}
		}
		res += 'N';
		return res;
	}
};


int main() {
	vector<int> input;
	int x;
	while (cin >> x) {
		input.push_back(x);
		if (cin.get() == '\n') break;
	}
	int y;
	cin >> y;
	solution2 solver;
	cout << solver.findNodePath(input, y);
}