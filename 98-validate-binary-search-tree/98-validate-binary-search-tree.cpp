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
    
    bool check_BST(TreeNode* root, long start, long end){
        if(!root) return true;
        if(root->val <= start || root->val >= end) return false;
        return check_BST(root->left, start, root->val) && check_BST(root->right, root->val, end);
    }
    
    bool isValidBST(TreeNode* root) {
        return check_BST(root, LONG_MIN, LONG_MAX);
        
    }
};