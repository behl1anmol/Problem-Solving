/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int pseudoPalindromicPathsUtils(struct TreeNode* root, int path){
    
    if(!root) return 0;
    
    path ^= (1 << root->val);
    
    if(!root->left && !root->right){
        return path & (path-1)?0:1;
    }
    return pseudoPalindromicPathsUtils(root->left, path) + pseudoPalindromicPathsUtils(root->right, path);
    
    
    
    
    
}


int pseudoPalindromicPaths (struct TreeNode* root){
    return pseudoPalindromicPathsUtils(root, 0);
}