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
    
    ListNode *getCycleBegin(ListNode *node, ListNode* head){
        
        ListNode *p1 = node->next;
        ListNode *p2 = node;
        int k = 1;
        while(p1!=p2){
            p1 = p1->next;
            //cout<<"counting nodes";
            k++;
        }
        cout<<k;
        
        p1 = p2 = head;
        
        for(int i=0;i<k;i++){
            p1 = p1->next;
        }
        
        while(p1!=p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        
        return p1;
        
        
        
    }
    
    ListNode *detectCycle(ListNode *head) {
        
        if(head == NULL || head->next == NULL) return NULL;
        
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast!=NULL && fast->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) break;
            //cout<<"checking loop"; 
        }
        if(fast==NULL || fast->next==NULL) return NULL;
        
        return getCycleBegin(fast, head);
    }
};