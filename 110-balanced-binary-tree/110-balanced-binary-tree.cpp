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
    int leftHeightTree(TreeNode* root){
        if(!root) return 0;
        
        return 1 + leftHeightTree(root->left);
    }
    int rightHeightTree(TreeNode* root){
        if(!root) return 0;
        return 1 + rightHeightTree(root->right);
    }
    int heightTree(TreeNode* root){
        if(!root) return 0;
        return 1 + max(heightTree(root->right), heightTree(root->left));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        int left = 1 + heightTree(root->left);
        int right = 1 + heightTree(root->right);
        
        if(abs(left-right)>1){
            //cout<<root->val<<" ";
            //cout<<left<<" ";
            //cout<<right<<" ";
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
        
    }
};