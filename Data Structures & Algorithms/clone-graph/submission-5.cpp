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
    unordered_map<Node*, Node*> oldToNew;

    Node* clone(Node* node){
        if(node == nullptr)return nullptr;
        if(oldToNew.find(node) != oldToNew.end()) return oldToNew[node];
        
        Node* c = new Node(node->val);
        oldToNew[node] = c;
        for(auto const n:node->neighbors){
            c->neighbors.push_back(clone(n));
        }
        return c;
    }
    Node* cloneGraph(Node* node) {
        return clone(node);
    }
};
