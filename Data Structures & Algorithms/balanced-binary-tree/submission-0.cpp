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
    bool isBalance = true;
    int helperDFS(TreeNode* root){
        if( root == nullptr){
            return 0;
        }
        // 在這邊可以取得子樹高度
        int leftHeight = helperDFS( root -> left);
        int rightHeight = helperDFS( root -> right);

        if(abs( leftHeight - rightHeight ) > 1){
            isBalance = false;
        }
  
        return 1 + max(rightHeight, leftHeight);
        



    }

    bool isBalanced(TreeNode* root) {
        helperDFS(root);
        return isBalance;
    }
};
