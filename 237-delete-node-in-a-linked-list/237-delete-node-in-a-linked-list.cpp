/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(!node) return;
        if(node->next == NULL){
            delete(node);
            node = NULL;
        }
        node->val = node->next->val;
        ListNode* del = node->next;
        node->next = node->next->next;
        delete(del);
    }
};