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
        
        if(head == NULL || head->next==NULL) return NULL;
        
        ListNode *temp = head;
        int m = 0;
        
        while(temp!=NULL){
            m++;
            temp = temp->next;
        }
        temp = head;
        
        for(int i=1;i<m-n;i++){
            temp = temp->next;
        }
        //cout<<m-n<<endl;
        //cout<<temp->val;
        if((m-n)==0){
            head = temp->next;
            return head;
        }
        
        temp->next = temp->next->next;
        
        return head;
    }
};