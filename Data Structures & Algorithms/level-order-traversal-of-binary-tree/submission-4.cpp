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

// It seems like using BFS might work.
// Since it's layer ordered 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        
        queue<TreeNode*> q;
        
        if(!root)return res;

        q.push(root);
        while(!q.empty()){
            vector<int> tempQueue;
            int layerSize = q.size();
            for(int i=0; i<layerSize; i++){
                TreeNode* temp = q.front();   
                q.pop();
                tempQueue.push_back(temp->val); 

                if(temp->left!=nullptr)q.push(temp->left);
                if(temp->right!=nullptr)q.push(temp->right);
            }
            res.push_back(tempQueue);
        }
        return res;
    }
};
