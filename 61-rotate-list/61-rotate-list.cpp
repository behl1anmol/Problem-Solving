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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        if(k==0 || head->next==NULL) return head;

        ListNode* temp = head;
        int len = 1;
        while(temp->next!=NULL){
            temp = temp->next;
            len++;
        }
        if(k==len) return head;
        temp->next = head;
        temp = head;

        if(len < k) k = k%len;
        len = len-k;
        cout<<len;
        for(int i=0;i<len-1;i++){
            temp = temp->next;
        }
        head = temp->next;
        temp->next = NULL;
        
        return head;
        
    }
};