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
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
       maxDiameter = 0;
       helper(root);
       return maxDiameter;

        
    }
    int helper(TreeNode* root){
        if(root == nullptr) return 0;
        // There are two situation:
        // 1. You're in the path
        int left = helper(root->left);
        int right = helper(root->right);


        // 2. You're the "root" of the longest path between any two nodes
        maxDiameter = max(left+right, maxDiameter);
        return 1 + max(left, right);

    }
        
};
