/**
* leetcode CT150 T00 相同的树
*/
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// 在c++11中引入了结构体的构造函数，可以使用多个构造函数
// 如下三个构造函数分别为
// 1、构造一个空二叉树
// 2、构造一个只有根节点的二叉树
// 3、构造一个有根节点、左子树、右子树的二叉树
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 注意此处一定要使用指针引用BinTree *& Node 或者是 指针的指针 BinTree ** Node，
// 如果仅仅是 BinTree * Node 创建出的树将是空的，
// 因为这是递归调用，需要使用指针或者引用进行值传递，
/**
* 先序构建二叉树
* 此代码存在问题，如果输入的数据序列不是正确先序二叉树顺序的话，可能生成错误的二叉树
* @param Node
* @param pData
*/
void preOrderCreate(TreeNode *&Node, int *pData)
{
	if (pData != nullptr) {
		if (*pData < -100 || *pData > 100) {
			Node = nullptr;
		} else {
			Node = new TreeNode(*pData);
			preOrderCreate(Node->left, ++pData);
			preOrderCreate(Node->right, ++pData);
		}
	}
}

/**
* 层序创建二叉树 基于队列实现
* @param Node
* @param pData
*/
void levelOrderCreate(TreeNode *&Node, vector<int> Data)
{
	auto it = 0;
	auto len = Data.size();
	queue<TreeNode *> q;
	TreeNode *tmp;
	if (Data[it] < -100 || Data[it] > 100) {
		Node = nullptr;
	}
	Node = new TreeNode(Data[it]);
	q.push(Node);
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		if (++it >= len)
			break;
		if (Data[it] > -100 && Data[it] < 100) {
			tmp->left = new TreeNode(Data[it]);
			q.push(tmp->left);
		} else {
			/* do nothing */
		}
		if (++it >= len)
			break;
		if (Data[it] > -100 && Data[it] < 100) {
			tmp->right = new TreeNode(Data[it]);
			q.push(tmp->right);
		} else {
			/* do nothing */
		}
	}
}

class Solution
{
public:
	/**
	 * 递归的思路就是把整体任务分解成为每一步都相同的小步骤
	 * @param p
	 * @param q
	 * @return
	 */
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		if (p == nullptr && q == nullptr) {
			return true;
		} else if (p == nullptr || q == nullptr) {
			return false;
		} else if (p->val != q->val) {
			return false;
		} else {
			return isSameTree(p->left, q->left) && isSameTree(p->right,q->right);
		}
	}
};

int main()
{
	vector<int> data1 = {1, 2};
	vector<int> data2 = {1, 111, 2};

	TreeNode *t1, *t2;
	levelOrderCreate(t1, data1);
	levelOrderCreate(t2, data2);
	Solution solve;
	cout << solve.isSameTree(t1, t2) << endl;
}