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
    
    unordered_map<int, int> indexMap;
   

    TreeNode* build(int preLeft, int preRight, int inLeft, int inRight, 
                    vector<int>& preorder, vector<int>& inorder){
    if (preLeft > preRight || inLeft > inRight) return nullptr;
    int rootVal = preorder[preLeft];                
    TreeNode* root = new TreeNode(rootVal);

    int inorderRootIndex = indexMap[rootVal];
    int leftSubtreeSize = inorderRootIndex - inLeft;

    root->left = build(preLeft + 1, preLeft + leftSubtreeSize,
                   inLeft, inorderRootIndex - 1, preorder, inorder);

    root->right = build(preLeft + leftSubtreeSize + 1, preRight,
                        inorderRootIndex + 1, inRight, preorder, inorder);

                        return root;

    }

    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        

        for(int i=0; i<preorder.size(); i++){
            // Build a map for looking up number in a tree;
            indexMap[inorder[i]] = i;
        }

        return build(0, preorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);

    }
};
