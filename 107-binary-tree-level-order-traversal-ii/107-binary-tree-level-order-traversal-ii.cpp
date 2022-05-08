/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> result;
        if(!root->left && !root->right){
            vector<int> ans;
            ans.push_back(root->val);
            result.push_back(ans);
            return result;
        }
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){

            int n = q.size();
            vector<int> ans;
            
            
            for(int i=0;i<n;i++){
                TreeNode* top = q.front();
                q.pop();
                ans.push_back(top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            result.push_back(ans);
            ans.clear();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};