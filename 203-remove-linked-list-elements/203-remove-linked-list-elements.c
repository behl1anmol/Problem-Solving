/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val){
    
    while(head && head->val == val){
        head = head->next;
    }
    if(!head) return NULL;
    
    head->next = removeElements(head->next, val);
    return head;
}