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
    int res;
    unordered_map<TreeNode*, pair<int, int>*> dp;
    void dfs(TreeNode* root){
        if(root == nullptr) return;

        dfs(root->left);
        dfs(root->right);


       
        int left_steal = 0;
        int left_not_steal = 0;
        int right_steal = 0;
        int right_not_steal = 0;


        if(root->right != nullptr){
            right_steal = dp[root->right]->first;
            right_not_steal = dp[root->right]->second;
        }
        if(root->left != nullptr){
            left_steal = dp[root->left]->first;
            left_not_steal = dp[root->left]->second;

        }

        int steal = root->val + left_not_steal + right_not_steal;
        int not_steal = max(left_not_steal,  left_steal) + max(right_steal, right_not_steal);

        pair<int, int> *tmp = new pair<int, int>({steal, not_steal});
        dp[root] = tmp;
        


    }
    int rob(TreeNode* root) {
        dfs(root);

        res = max(dp[root]->first, dp[root]->second);
        for (auto& [key, val] : dp) {
            delete val;
        }
        
        return res;
    }
};