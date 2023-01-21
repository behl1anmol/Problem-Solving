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
    void _maxDepth(TreeNode* root, int currDepth, int &maxDepthTree){
        if(root==NULL) return;
        if(maxDepthTree < currDepth) maxDepthTree = currDepth;
        _maxDepth(root->left, currDepth+1, maxDepthTree);
        _maxDepth(root->right, currDepth+1, maxDepthTree);
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int maxDepthTree = 1;
        _maxDepth(root, 1, maxDepthTree);
        return maxDepthTree;
    }
};