// tag:binary_tree
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

class Solution
{
private:
    long prev = INT64_MIN;
    bool flag = true;

public:
    // 迭代遍历，记录中置数据
    bool isValid(TreeNode *root)
    {
        if (!root)
            return true;
        bool l = isValid(root->left);
        if (root->val <= prev)
        {
            return false;
        }
        prev = root->val;
        bool r = isValid(root->right);
        return l && r;
    }
    // inorder 迭代遍历
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode *> st;
        int tmp = INT32_MIN;
        while (root || !st.empty())
        {
            while (root)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if (root->val >= tmp)
            {
                tmp = root->val;
            }
            else
            {
                return false;
            }
            root = root->right;
        }
        return true;
    }
};

int main()
{
}