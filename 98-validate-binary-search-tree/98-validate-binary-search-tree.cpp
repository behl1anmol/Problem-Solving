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
    
    void calculate_inorder(TreeNode* root, vector<int> &inorder){
        if(!root) return;
        
        if(root->left) calculate_inorder(root->left, inorder);
        inorder.push_back(root->val);
        if(root->right) calculate_inorder(root->right, inorder);
    }
    
    
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        
        calculate_inorder(root, inorder);
        
        for(int i=0;i<inorder.size();i++){
            cout<<inorder[i];
        }
        
         if(unique(inorder.begin(), inorder.end()) != inorder.end())
             return false;
        
        bool asc = is_sorted(inorder.begin(), inorder.end());
                
        return asc;
    }
};