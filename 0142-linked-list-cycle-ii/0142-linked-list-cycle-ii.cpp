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
    
    bool hasCycle(ListNode* &slow, ListNode* &fast){

        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
        }
        
        return false;

    }
    
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow = head, *fast = head;
        if(!hasCycle(slow, fast)) return NULL;
        
        slow = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }

        
        return slow;
        
        
    }
};