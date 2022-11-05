/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) { 
    if(head == NULL) return NULL;
    if(head->next == NULL){ 
        Node* ans = new Node(head->val);
        if(head->random){
            ans->random = ans;
        }
        return ans;
    }
        
    unordered_map<Node*, Node*> mp;
    Node* temp = head;

    //creating head node
    Node* c_head =  new Node(temp->val);
    //adding head node to map
    mp[temp] = c_head;
    //creating next node for head
    c_head->next = new Node(temp->next->val);
    //adding next node of head to map
    mp[temp->next] = c_head->next;
    //creating random node and adding to map
    if(temp->random){
        if(mp.find(temp->random)!=mp.end()){
            c_head->random = mp[temp->random];
        }
        else{
            c_head->random = new Node(temp->random->val);
            mp[temp->random] = c_head->random;
        }
    }
    temp = temp->next;
    Node* ans = c_head;
    c_head = c_head->next;
    while(temp != NULL){
        //cout<<temp->val<<endl;
        if(temp->next != NULL){
            if(mp.find(temp->next) != mp.end()){
                c_head->next = mp[temp->next];
            }
            else{
                c_head->next = new Node(temp->next->val);
                mp[temp->next] = c_head->next;
            }
        }
        if(temp->random != NULL){
            if(mp.find(temp->random) != mp.end()){
                c_head->random = mp[temp->random];
            }
            else{
                c_head->random = new Node(temp->random->val);
                mp[temp->random] = c_head->random;
            }
        }            

        temp = temp->next;
        c_head = c_head->next;
    }
    return ans;

    }
};