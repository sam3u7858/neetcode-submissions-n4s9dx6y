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
    int res = INT_MIN;
    bool found = false;
    void dfs(TreeNode* root, int& currentK ,int k){
        if(root == nullptr || found) return;
        
        dfs(root->left, currentK, k);
        
        if(currentK == k){
            res = root->val; 
            found = true;
        } 
        currentK +=1;
        dfs(root->right, currentK, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int currentK = 1;
        dfs(root, currentK, k);
        return res;
        
    }
};
