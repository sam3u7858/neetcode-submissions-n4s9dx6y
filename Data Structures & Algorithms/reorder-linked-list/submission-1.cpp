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
    void reorderList(ListNode* head) {
        // Version 2
        if (!head || !head->next) return;   //：避免對 0 或 1 節點操作
        // 好，我要先把 n-1 -> n-2 -> n-3 分離出來..
        // 這樣會耗費 O(n) 時間複雜度
        // 並且原本的list會被切成兩條
        // 1->2->3->4-> ... ->n/2 - 1
        // n-1 -> n-2 -> n-3 -> ... -> n/2
        // 嗯...這是一個方法，不過這需要額外紀錄 n 的大小
        // 我看了 Hint，看來我前半段的方法是正確的
        // 原來 slow/fast pointer 可以這樣用!?
        // 好，我接下來會建立兩個變數
        // 這樣剛好可以巧妙運用 fast & slow pointer + linked list的特性，很好
        // 先用 fast & slow pointer 相撞點找到中點

        // 啊，不過這個方法似乎在評分端會造成 Runtime Error (NZEC)
        // 可能是 在評分端裡面呼叫了 head 的遍歷
        // 所以，我打算先採用第一個方法


        // int n = 0;
        // ListNode* current = head;
        // while(current != nullptr){
        //     current = current -> next;
        //     n +=1;
        // }
        // int mid = n/2;

        // cout << n/2 << endl;


        // 啊，原來提示的 To reorder the list, we connect the first and last nodes 意思不太依樣
        // fast / slow 是這樣用的:
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* beforeSlow = nullptr; // 改成記錄 slow 的前一個節點，這邊如果用 new dummy 的話不但無法成功截斷，還有機會造成奇怪的狀況

        while (fast && fast->next) {
            beforeSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // 這樣一來，我們就可以透過 slow -> n/2
        // fast -> n  走到終點
        // 我們把倒轉後的n/2->n 的n設為before slow的下一個值(就會變成) [inplace][reverse]

        // from n/2->n 慢慢(slow -> fast) 倒轉
        ListNode* prev = nullptr;
        ListNode* current = slow;

        // 加入這一行，**正確斷開前半部與後半部**
        if (beforeSlow != nullptr) {
            beforeSlow->next = nullptr;
        }

        while(current != nullptr){
            ListNode* temp = current -> next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        // Insert the node:

        ListNode* first = head;
        ListNode* second = prev; // ❗️prev 是反轉後的起點，不能用 slow

        while (second && first) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            if (tmp1 == nullptr) break; // 如果前半部已經到底，避免 second->next 錯誤寫入
            second->next = tmp1;

            first = tmp1;
            second = tmp2;
        }
    }
};
