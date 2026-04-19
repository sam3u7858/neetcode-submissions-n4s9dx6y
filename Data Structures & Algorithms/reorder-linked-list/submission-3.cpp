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

private:
    ListNode* reverse(ListNode* head){
        ListNode* rev = nullptr;
        while(head){
            ListNode* next = head->next;
            head->next = rev;
            rev = head;
            head = next;
        }

        

        return rev;
    }

public:
    void reorderList(ListNode* head) {

        if(!head->next)return;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;



        while (fast && fast->next) {
            prev = slow;          
            slow = slow->next;    
            fast = fast->next->next; 
        }

        if (prev) {
            prev->next = nullptr; 
        }
        auto* l2 = reverse(slow);
        auto* l1 = head;


        while(l1 && l2){
            auto* next1 = l1->next;
            auto* next2 = l2->next;

            l1->next = l2;
            if(next1 == nullptr) break;
            l2->next = next1;

            l2 = next2;
            l1 = next1;

        }

      

       
    }
};
