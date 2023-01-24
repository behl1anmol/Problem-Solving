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
    int count = 0; 
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        
        int res = kthSmallest(root->left,k);
        
        if(res >= 0){
            return res;
        }
        count++;
        if(count == k) return root->val;
        
        res = kthSmallest(root->right, k);
        if(res >=0) return res;
        
        return -1;   
    }
};