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
   
    pair<int,int> dfs(TreeNode* root) {
        if (!root) return {0, 0};
        auto [ls, ln] = dfs(root->left);
        auto [rs, rn] = dfs(root->right);
        int steal = root->val + ln + rn;
        int not_steal = max(ls, ln) + max(rs, rn);
        return {steal, not_steal};
    }
    int rob(TreeNode* root) {
        auto const a = dfs(root);

        res = max( a.first,  a.second);
       
        return res;
    }
};