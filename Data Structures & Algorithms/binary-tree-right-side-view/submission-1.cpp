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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        vector<int> res;
        queue<TreeNode*> bq;
        bq.push(root);

        while(!bq.empty()){
            int qsize = bq.size();
            for(int i=0; i<qsize; i++){
                
                TreeNode* curr = bq.front();
                bq.pop();
                if(i == qsize - 1) res.emplace_back(curr->val);

                
                if(curr->left){
                    bq.push(curr->left);
                }
                if(curr->right){
                    bq.push(curr->right);
                }

                
            }






        }
        return res;

    }
};
