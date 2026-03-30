/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int max_diameter = 0;

    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;

        int left = dfs(node->left);
        int right = dfs(node->right);

        max_diameter = std::max(max_diameter, left + right);

        return 1 + std::max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return max_diameter;
    }
};
