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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(0); // Dummyhead
        ListNode* startOfDummyHead = dummyHead; 

        while(list1 != nullptr && list2 != nullptr){
            int a = list1->val;
            int b = list2->val;

            if(a>b){
                // Example a=2, b=1, we put b first, a inplace
                dummyHead->next = list2;
                list2 = list2->next;
                dummyHead = dummyHead->next;
                cout << dummyHead->val;
            }
            else{
                dummyHead->next = list1;
                list1 = list1->next;
                dummyHead = dummyHead->next;
                cout << dummyHead->val;
            }
        }

        // Proceed with non nullptr;
        if(list1 == nullptr ){
            dummyHead -> next = list2;
        }
        else{
            dummyHead -> next = list1;
        }
        
        return startOfDummyHead->next;

    }
};
