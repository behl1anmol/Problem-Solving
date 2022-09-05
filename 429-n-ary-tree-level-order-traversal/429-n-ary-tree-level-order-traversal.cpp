/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> q;
        
        q.push(root);
        ans.push_back({root->val});
        
        while(!q.empty()){
            
            int n = q.size();
            vector<int> lvl;
            while(n--){
                Node* front = q.front();
                q.pop();
                
            
                for(int i=0; i<front->children.size();i++){
                    //cout<<front->children.size()<<" ";
                    q.push(front->children[i]);
                    lvl.push_back(front->children[i]->val);
                }
                //if(!lvl.empty()) ans.push_back(lvl);
                //lvl.clear();
            }
                if(!lvl.empty()) ans.push_back(lvl);
                lvl.clear();
        }
        return ans;
    }
};