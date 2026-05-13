/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
   public:
    Node* cloneGraph(Node* node) {

        if(node == nullptr) return nullptr;
        vector<int> visited(101, 0);
        vector<Node*> nodes(101, nullptr);

        Node* clone = new Node(node->val);
        nodes[clone->val] = clone;

        dfs(node, clone, visited, nodes);

        return clone;
    }

   private:
   void dfs(Node* node, Node* clone, vector<int>& visited, vector<Node*>& nodes) {
        if (!node || visited[node->val]) return;
        visited[node->val] = 1;

     
        vector<Node*> adjs = node->neighbors;
        for (Node* a : adjs) {
            if (nodes[a->val] != nullptr) {
                clone->neighbors.push_back(nodes[a->val]);
                continue;
            } else {
                // Copy the neighbor
                Node* neighbor = new Node(a->val);
                nodes[a->val] = neighbor;
                clone->neighbors.push_back(neighbor);
                dfs(a, neighbor, visited, nodes);
                
            }
        }

        
    }
};
