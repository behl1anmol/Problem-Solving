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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(NULL);
        double count = 0;
        double sum = 0;
        
        while(q.size() > 1){
            
            TreeNode* front = q.front();
            q.pop();
            
            if(front==NULL){
                
                ans.push_back((sum/count));
                //cout<<(sum/count)<<endl;
                q.push(NULL);
                count = 0;
                sum = 0;
            }
            else{
                //cout<<front->val<<" ";
                sum += front->val;
                count++;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }    
        }
        ans.push_back((sum/count));
        return ans;
    }
};