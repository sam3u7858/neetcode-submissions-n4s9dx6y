/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* dummyHead = head;
        // Weird method 1:
        // Since 1000 <= val  <= 1000
        // We can set visit = 1001

        while(head != nullptr){
            if(head->next == nullptr){
                return false;
            }
            if(head->val == 1001){
                return true;
            }

            head->val = 1001;
            head = head->next;
            
        }

        return false;

    }
};
