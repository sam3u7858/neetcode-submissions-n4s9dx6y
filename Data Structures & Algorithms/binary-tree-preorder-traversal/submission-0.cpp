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

    void dfs(vector<int>& t, TreeNode* root){
        if(root == nullptr) return;
        
       
        t.push_back(root->val);
        dfs(t, root->left);
        dfs(t, root->right);
        return;



    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(res, root);

        return res;

        
    }
};