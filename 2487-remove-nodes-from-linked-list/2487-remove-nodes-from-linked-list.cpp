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
    ListNode* removeNodes(ListNode* head) {
        if(!head || !head->next) return head;
        stack<int> st;
        ListNode* temp = head;
        ListNode* reverse = NULL;
        while(temp){
            st.push(temp->val);
            temp = temp->next;
        }
        stack<int> new_st;
        
        int top = st.top();
        new_st.push(top);
        st.pop();
        
        while(!st.empty()){
            top = st.top();
            if(top >= new_st.top()){
                new_st.push(top);
            }
            st.pop();
        }
        
        ListNode* new_head = NULL;
        top = new_st.top();
        new_head = new ListNode(top);
        head = new_head;
        new_st.pop();
        
        while(!new_st.empty()){
            top = new_st.top();
            new_head->next = new ListNode(top);
            new_st.pop();
            new_head = new_head->next;
        }
        return head;
    }
};