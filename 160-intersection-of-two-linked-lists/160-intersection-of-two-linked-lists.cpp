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
    
    int size_ll(ListNode *head){
        int count=0;
        ListNode *temp = head;
        
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    
    ListNode* find_intersection(ListNode *big, ListNode *small,int diff){
        
        
        
        for(int i=0;i<diff;i++){
            big=big->next;
        }
        while(big!=NULL){
            if(big==small){
                return big;
                break;
            }
            big = big->next;
            small = small->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int sizeA = size_ll(headA);
        int sizeB = size_ll(headB);
        
        /*cout<<"sizeA:"<<sizeA;
        cout<<"\nsizeB:"<<sizeB;*/
        
        int diff = abs(sizeA-sizeB);
        //cout<<"\nDIFF:"<<diff<<endl;
        
        ListNode *big;
        ListNode *small;
        
        if(sizeA>sizeB){
            big = headA;
            small = headB;
        
        }
        else{
            big = headB;
            small = headA;
        }
        
        ListNode *intersectVal = find_intersection(big, small,diff);
        
        if(intersectVal==NULL){
            return NULL;
        }
    
        return intersectVal;
        
        
        
        
    }
};