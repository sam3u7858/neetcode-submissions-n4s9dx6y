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
    int res = 0;
    
   
    
    int dfs(TreeNode* root){
        
       if(root == nullptr){
        return 0;
       }
       int leftHeight = dfs(root -> left);
       int rightHeight = dfs(root -> right);
       
       res = max(res, leftHeight+rightHeight);
       return 1 + max(leftHeight, rightHeight);

    }


    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};
