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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;

        queue<TreeNode*> bq;
        bq.push(root);
        while(!bq.empty()){
            vector<int> tmp;
            int qSize = bq.size();

            for(int i=0; i<qSize; i++){
                TreeNode* curr = bq.front();
                bq.pop();
                
                tmp.push_back(curr->val);
                if(curr->left) bq.push(curr->left);
                if(curr->right) bq.push(curr->right);
                
            }

            res.emplace_back(tmp);

        }
        
        return res;
    }
};
