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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if((left == right == 1) || !head || !head->next ) return head; 
        ListNode* curr = NULL;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* n1 = NULL;
        ListNode* n2 = NULL;
        ListNode* r = head;
        ListNode* l = head;
        
        for(int i=1;i<right;i++)
        {
            r = r->next;
        }
        for(int i=1;i<left;i++)
        {
            if(i==left-1) n1 = l;
            l = l->next;
        }
        if(l->next==r){
            swap(l->val, r->val);
            return head;
        }
        cout<<"left:"<<l->val<<" right:"<<r->val;
        curr = l;
        n2 = r->next;
        
        while(curr!=n2){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        //cout<<"\nprev:"<<prev->val<<" curr:"<<curr->val<<" next:"<<next->val;
        if(curr)l->next = curr;
       if(n1) n1->next = prev;
        
        return left==1?prev: head;
    }
};