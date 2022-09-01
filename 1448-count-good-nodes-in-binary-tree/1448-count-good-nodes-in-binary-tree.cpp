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
    
    void getGoodNodes(TreeNode *root, int currMax, int &ans){
        
        if(!root) return;
        
        if(currMax <= root->val){
            currMax = root->val;
            ans++;
            //cout<<root->val<<endl;
        }
        
        if(root->left) getGoodNodes(root->left, currMax, ans);
        if(root->right) getGoodNodes(root->right, currMax, ans);
        

    }
    
    
    
    
    
    int goodNodes(TreeNode* root) {
        int ans = 0;
        getGoodNodes(root, root->val, ans);
        
        return ans;
    }
};