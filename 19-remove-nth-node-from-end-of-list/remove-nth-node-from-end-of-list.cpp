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
        int k =0;
        ListNode* ptr=head;
        while(ptr!=NULL){
            k++;
            ptr =ptr->next;
        }
        if(k==n) return head->next;
        int loc =k-n;
        ptr =head;
        while(--loc){
            ptr =ptr->next;
        }
        ptr->next =ptr->next->next;
        return head;
    }
};