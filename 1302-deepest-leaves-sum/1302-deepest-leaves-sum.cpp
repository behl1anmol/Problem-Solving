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
    void _deepestLeavesSum(TreeNode* root, int currLevel, int &maxLevel, int &sum){
        
        if(!root) return;
        if(!root->left && !root->right){
            if(currLevel > maxLevel){
                maxLevel = currLevel;
                sum = root->val;
            }
            else if(currLevel == maxLevel) sum += root->val;
        }
        else{
            _deepestLeavesSum(root->left, currLevel+1, maxLevel, sum);
            _deepestLeavesSum(root->right, currLevel+1, maxLevel, sum);
        }
    }
    int deepestLeavesSum(TreeNode* root) {

        int sum = 0;
        int level = 0;
        _deepestLeavesSum(root, 0, level, sum);
        return sum;
        
    }
};