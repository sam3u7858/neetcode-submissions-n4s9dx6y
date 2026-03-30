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
    vector<int> res;
    void dfs(TreeNode* node, int curr_max){
        if(!node) return;
        
        if(curr_max <= node->val){
            res.push_back(node->val);
            curr_max = node->val;
        }

        dfs(node->left, curr_max);
        dfs(node->right, curr_max);


    }

    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return res.size();
    }
};
