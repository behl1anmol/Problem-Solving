/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* _reverseList(struct ListNode* curr, struct ListNode* prev){
    if(curr->next == NULL){
        curr->next = prev;
        return curr;
    }
    struct ListNode* newHead = _reverseList(curr->next, curr);
    curr->next = prev;
    
    return newHead;
}

struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    return _reverseList(head, NULL);
}