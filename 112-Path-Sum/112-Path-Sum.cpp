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
    //vector<vector<int>>ans;
    bool ans = false;
    void dfs(TreeNode* root, int target, int sumTillNow, vector<int> path){
        
        
        sumTillNow = sumTillNow + root->val;
        path.push_back(root->val);
        
        if(!root->left && !root->right){
            if(sumTillNow == target) ans = true;
        }
        
        if(root->left) dfs(root->left, target, sumTillNow, path);
        if(root->right) dfs(root->right, target, sumTillNow, path);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        vector<int>path;
        dfs(root, targetSum, 0, path);
        return ans;
    }
};