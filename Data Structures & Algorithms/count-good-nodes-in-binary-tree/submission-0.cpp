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
    int goodCount = 0;
    void nodFinding(TreeNode* root, int max){
        if(root == nullptr){
            return;
        }
        
        if(root->val >= max){
            goodCount += 1;
            max = root->val;
        }
        nodFinding(root->left, max);
        nodFinding(root->right, max);
    }


    int goodNodes(TreeNode* root) {
        nodFinding(root, -101); 
        return goodCount;
    }
};
