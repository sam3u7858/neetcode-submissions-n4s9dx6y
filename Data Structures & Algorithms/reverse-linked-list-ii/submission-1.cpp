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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;

        for(int i=0; i<left-1; i++){
            prev = curr;
            curr = curr->next;
        }
        ListNode* _prev = nullptr;
        for(int i=0; i<right-left+1; i++){
            ListNode* tmpNext = curr->next;
            curr->next = _prev;
            _prev = curr;
            curr = tmpNext;
        }

        prev->next->next = curr;
        prev->next = _prev;

        return dummy->next;
    }
};