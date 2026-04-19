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
        int u = 0;

        if(head->next == nullptr) return nullptr;

        ListNode* curr = head;
        
        
        while(curr){
            u+=1;
            curr = curr->next;
        }

        int target = u-n;
        curr = head;
        int i = 0;

        if(target == 0) return head->next;
        while(curr){
            if(i == target-1){
                if(curr->next) curr->next = curr->next->next;
                else{
                    curr->next = nullptr;
                }
                break;
            }
            i++;
            curr = curr->next;
        }



        return head;

    }
};
