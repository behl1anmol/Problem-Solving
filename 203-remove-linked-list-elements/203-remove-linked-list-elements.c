/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 void _removeElements(struct ListNode* head, struct ListNode* prev, int val){
    if(head == NULL) return;
    
    if(head->val==val)
        prev->next = head->next;
    else
        prev = head;
    _removeElements(head->next, prev, val);    
}
struct ListNode* removeElements(struct ListNode* head, int val){
    if(!head) return head;
    while(head && head->val == val){
        head = head->next;
    }
    _removeElements(head, NULL, val);
    
    return head;
    
}