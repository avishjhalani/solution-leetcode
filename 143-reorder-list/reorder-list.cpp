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
        ListNode* slow =head ;
        ListNode* fast =head;
        while(fast && fast->next){
            slow = slow->next;
            fast =fast->next->next;
        }
        ListNode* sec = slow->next;
        ListNode* node = nullptr;
        slow->next =nullptr;
        while(sec){
            ListNode* temp = sec ->next;
            sec->next =node;
            node =sec;
            sec =temp;
        }

        ListNode* first =head;
        sec =node;
        while(sec){
            ListNode* temp1 = first->next;
            ListNode* temp2 = sec ->next;
            first->next = sec;
            sec ->next = temp1;
            first =temp1;
            sec =temp2;
        }
        

    }
};