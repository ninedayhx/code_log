// tag: dfs 深度优化 bfs 广度优先
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
public:
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int
        {
            if (!node)
                return 0;
            int l_val = dfs(node->left);
            int r_val = dfs(node->right);
            ans = max(ans, l_val + r_val + node->val);
            return max(max(l_val, r_val) + node->val, 0);
        };
        dfs(root);
        return ans;
    }
};

int main()
{
    TreeNode *tree = new TreeNode(-10);
    tree->left = new TreeNode(9);
    tree->right = new TreeNode(20);
    tree->right->left = new TreeNode(15);
    tree->right->right = new TreeNode(7);
    Solution solver;
    cout << solver.maxPathSum(tree) << endl;
}