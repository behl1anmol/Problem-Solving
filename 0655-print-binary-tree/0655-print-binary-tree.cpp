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
    int maxDepth(TreeNode* root) {
            
        if(!root) return 0;
        
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    }
    
    void _printTree(TreeNode* root, int m, int n, vector<vector<string>> &tree, int height){
        if(root->left){
            int nl = n - pow(2, height-1-m-1);
            tree[m+1][nl] = to_string(root->left->val);
            _printTree(root->left, m+1, nl, tree, height);
        }
        if(root->right){
            int nl = n + pow(2, height-1-m-1);
            tree[m+1][nl] = to_string(root->right->val);
            _printTree(root->right, m+1, nl, tree, height);
        }
    }
    
    vector<vector<string>> printTree(TreeNode* root) {
        if(!root){
            vector<vector<string>> tree;
            return tree;
        }
        
        int height = maxDepth(root);
        //cout<<height<<" ";
        int col  = pow(2,height)-1;
            
        vector<vector<string>> tree(height, vector<string>(col, ""));
        
        int m = 0;
        int n = (col-1)/2;
        tree[0][n]  = to_string(root->val);
        
        _printTree(root, m, n, tree, height);
        
        return tree;
    }
    
};