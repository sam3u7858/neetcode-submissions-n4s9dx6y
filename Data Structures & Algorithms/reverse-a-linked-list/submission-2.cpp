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
    ListNode* reverseList(ListNode* head) {
        ListNode* tempHead = nullptr;
        

        while(head != nullptr){
            // Keep the next pointer for restore data 
            ListNode* tempNext = head->next;

            // Make the pointer reverse
            head->next = tempHead;

            // Move forward to next node
            tempHead = head;

            // Move head to next head
            head = tempNext;
           
        }

        return tempHead;
    }
};
