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
    int maxValue = INT_MIN;
    
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftMax = max(dfs(root->left), 0);
        int rightMax = max(dfs(root->right), 0);
        
        // If current node is root node for path
        // We simply takes two value
        maxValue = max(maxValue, root->val + leftMax + rightMax);
        return root->val + max(leftMax, rightMax);

    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxValue;
    }
};
