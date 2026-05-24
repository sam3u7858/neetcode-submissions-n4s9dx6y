/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    unordered_map<Node*, Node*> table;

    Node* deepcopy(Node* node){
        if(node == nullptr) return nullptr;
        if(table.find(node)!=table.end()) return table[node];

        Node* tmp = new Node(node->val);
        table[node] = tmp;
        tmp->next = deepcopy(node->next);
        tmp->random = deepcopy(node->random);

        return tmp;        
    }

    Node* copyRandomList(Node* head) {
        return deepcopy(head);
    }
};
