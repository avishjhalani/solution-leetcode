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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr) return head;
        
        ListNode* p1 =head;
        while(p1->next!=nullptr){
            if(p1->next->val==val){
                p1->next =p1->next->next;
            }
            else{
                p1 = p1->next;
            }
        }
        if(head->val == val){
            head = head->next;
        }
        return head;
    }
};