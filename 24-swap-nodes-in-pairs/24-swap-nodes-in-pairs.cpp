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
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode* curr = head;
        ListNode* nxt = head->next;
        ListNode* back = NULL;
        
        head = head->next;
        
        while(curr && nxt){
            if(back) back->next = nxt;
            
            curr->next = nxt->next;
            nxt->next = curr;
            
            back = curr;
            curr = curr->next;
            if(curr) nxt = curr->next;
            
        }
        return head;
        
    }
};