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
    
    void _reverseOddLevels(TreeNode* l, TreeNode* r, int level){
        if(!l && !r) return;
        
        if(l && r && (level%2))
            swap(l->val, r->val);
        
        _reverseOddLevels(l->left, r->right, level+1);
        _reverseOddLevels(l->right, r->left, level+1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        
        _reverseOddLevels(root->left, root->right, 1);
        return root;
    }
};