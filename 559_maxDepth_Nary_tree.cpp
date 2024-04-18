/***
 * n叉树的最大深度
 * 主要就是学习一下，多叉树的数据结构，在华子的题里有涉及到，如果不会构建这种数据结构
 * 可能会比较难做
 */
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

/**
 * 多叉树的最大深度，与二叉树的最大深度一致
 * @param root
 * @return
 */
int maxDepth_Nrytree(Node* root) {

}