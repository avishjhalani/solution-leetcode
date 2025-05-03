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
    ListNode *solve(ListNode *head, int count, int k) {
        if (head == NULL or head->next == NULL) {
            return head;
        }
        if (count < k)
            return head;
    
    ListNode* prev = NULL;
    ListNode* curr = head;
    int a = 0;
    while(curr != NULL and a < k) {
        ListNode* nextNode = curr->next;
        curr->next=prev;
        prev = curr;
        curr = nextNode;
        a++;
    }
    head ->next =solve(curr,count-k,k);
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* curr = head;
        while (curr) {
            curr = curr->next;
            count++;
        }
        return solve(head, count, k);
    }
};