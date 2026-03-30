class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 先建立原節點 -> 新節點的對應表
        unordered_map<Node*, Node*> node_map;

        Node* curr = head;
        while (curr) {
            node_map[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // 第二次掃描，處理 next 和 random 指標
        curr = head;
        while (curr) {
            node_map[curr]->next = node_map[curr->next];
            node_map[curr]->random = node_map[curr->random];
            curr = curr->next;
        }

        return node_map[head];
    }
};