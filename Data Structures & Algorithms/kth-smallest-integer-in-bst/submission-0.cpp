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


//原來這題目是想要考 in-order traversal,
class Solution {
public:
    int res = INT_MAX;
    int cnt = 0; // side effect could happen!
    void dfs(const TreeNode* root, int k){
        if(root == nullptr){
            return;
        }

        

        // inorder
        dfs(root->left, k);
        
        cnt += 1;
        if(cnt == k){
            res = root->val; // side effect could happen!
        }

        dfs(root->right, k);


    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
};
