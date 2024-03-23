/**
* leetcode CT150 T27 二叉树的最大深度
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
struct BinTree {
	int val;
	BinTree *left;
	BinTree *right;
	BinTree() : val(0), left(nullptr), right(nullptr) {}
	BinTree(int x) : val(x), left(nullptr), right(nullptr) {}
	BinTree(int x, BinTree *left, BinTree *right) : val(x), left(left), right(right) {}
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
void preOrderCreate(BinTree *&Node, int *pData)
{
	if (pData != nullptr) {
		if (*pData < -100 || *pData > 100) {
			Node = nullptr;
		} else {
			Node = new BinTree(*pData);
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
void levelOrderCreate(BinTree *&Node, int *pData)
{
	queue<BinTree *> q;
	BinTree *tmp;
	if (*pData < -100 || *pData > 100) {
		Node = nullptr;
	}
	Node = new BinTree(*pData);
	q.push(Node);

	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		pData++;
		if (*pData > -100 && *pData < 100) {
			tmp->left = new BinTree(*pData);
			q.push(tmp->left);
		} else {
			/* do nothing */
		}
		pData++;
		if (*pData > -100 && *pData < 100) {
			tmp->right = new BinTree(*pData);
			q.push(tmp->right);
		} else {
			/* do nothing */
		}
	}
}


/**
 * 先序遍历二叉树 递归实现
 * @param BT
 */
void preOrderTraversal(BinTree *BT)
{
	if (BT) {
		cout << BT->val << ' ';
		preOrderTraversal(BT->left);
		preOrderTraversal(BT->right);
	}
}

class Solution
{
public:
	int res = 0;
	//
	int maxDepth(BinTree *root)
	{
		//基本思想：递归，深度优先搜索
		Recursion(root, 0);
		return res;
	}
	void Recursion(BinTree *root, int depth)
	{
		if (root == NULL) {
			if (depth > res)  //如果当前的分支的深度大于已经获得的最大深度，则将当前深度设置为最大深度
				res = depth;
		} else {
			Recursion(root->left, depth + 1);
			Recursion(root->right, depth + 1);
		}
	}
};

int main()
{
	int tree[7] = {3, 9, 20, 111, 111, 15, 7};
	BinTree *bintree;
	levelOrderCreate(bintree, tree);
	Solution solve;
	cout<<solve.maxDepth(bintree)<<endl;
}