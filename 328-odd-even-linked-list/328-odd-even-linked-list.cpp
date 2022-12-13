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
        ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* l1 = head;
        ListNode* l2 = head->next;

        while(odd && even){
            odd->next = even?even->next:NULL;
            odd = odd->next;
            even->next = odd?odd->next:NULL;
            even = even->next;
        }

        odd = l1;
        while(odd->next){
            odd = odd->next;
        }
        odd->next = l2;
        return l1;
    }

};