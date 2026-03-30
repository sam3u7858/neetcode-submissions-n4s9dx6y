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
    Node* copyRandomList(Node* head) {
        unordered_map<int, Node*> p;
        unordered_map<Node*, int> random_map;
        vector<Node*> random_pointer;
        vector<int> val;


        if(head == nullptr){
            return head;
        }

        Node* curr = head;
        int i = 0;
        while(curr != nullptr){
            val.push_back(curr -> val);
            random_pointer.push_back(curr -> random);
            random_map[curr] = i;
            curr = curr -> next;
            i++;
        }

        // Rebuild Node:
        curr = new Node(val[0]);
        p[0] = curr;
        for(int i=1; i<val.size(); i++){
           curr = new Node(val[i]);
           p[i] = curr;
        }

        // Reconstuct the link
        for(int i=0; i<p.size(); i++){
            if(i<p.size()-1){
                p[i]->next = p[i+1];
            }
            if(random_pointer[i] != nullptr){
                p[i] -> random = p[random_map[random_pointer[i]]];
            }
        } 

        return p[0];
        

    }
};
