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

class Codec {
public:
    // USE BFS
    // Encodes a tree to a single string.

    vector<string> split(const string& str, char delimiter) {
        vector<string> result;
        stringstream ss(str);
        string token;

        while (getline(ss, token, delimiter)) {
            result.push_back(token);
        }
        return result;
    }
    
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";

        queue<TreeNode*> q;
        vector<string> result;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node == nullptr) {
                result.push_back("n");
            } else {
                result.push_back(to_string(node->val));
                q.push(node->left);
                q.push(node->right);
            }
        }

        // 去除尾部多餘的 "n"
        while (!result.empty() && result.back() == "n") {
            result.pop_back();
        }

        // 組合結果為字串
        string serialized;
        for (const string& s : result) {
            serialized += s + ",";
        }
        if (!serialized.empty()) serialized.pop_back();  // 移除最後一個逗號
        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // split stream
        if(data.empty()) return nullptr;
        vector<string> tk = split(data, ',');
        TreeNode* root = new TreeNode(stoi(tk[0]));
        queue<TreeNode*> q;

        q.push(root);
        int i = 1;
        
        while(!q.empty() && i < tk.size()){
            // pop from queue
            TreeNode* cur = q.front(); q.pop();
            // left node
            if(i < tk.size() && tk[i] != "n"){
                cur->left = new TreeNode(stoi(tk[i]));
                q.push(cur->left);
            }
            i++;

            if(i < tk.size() && tk[i] != "n"){
                cur->right = new TreeNode(stoi(tk[i]));
                q.push(cur->right);
            }
            i++;
        }
        return root;
        
    }
};
