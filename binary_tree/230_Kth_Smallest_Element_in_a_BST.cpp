// tag: binary_tree BST 二叉搜索树
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @brief 深度优先搜索，找到第k个
 *        迭代形式
 * @param root
 * @param k
 * @return int
 */
int kthSmallest(TreeNode *root, int k)
{
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty())
    {
        // 向左进行深度搜索
        while (root)
        {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        if (--k == 0)
        {
            return root->val;
        }
        st.pop();
        root = root->right;
    }
    return -1;
}

int main()
{
}