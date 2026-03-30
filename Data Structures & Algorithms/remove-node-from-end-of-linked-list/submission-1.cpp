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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head->next == nullptr && n==1){
            return nullptr;
        }

      
        ListNode* first = head;
        ListNode* second = new ListNode(0);
        second -> next = head; // if the removable target is at head

        int steps = 1;
        while(first != nullptr){
            first = first -> next;
            if(steps > n){
                second = second -> next;
            }
            steps++;
        }

        // remove second->next;
        cout << second->val;
        
        if(second -> next == head){
            head = head -> next;
        }
        else{
            second -> next = second -> next -> next;
        }
        return head;

    }
};
