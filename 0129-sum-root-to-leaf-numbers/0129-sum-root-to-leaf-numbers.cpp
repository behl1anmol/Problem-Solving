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
    int _sumNumbers(TreeNode* root, string num){
        
        num = num + to_string(root->val);

        if(!root->left && !root->right){
            int numi = stoi(num); 
            return numi;
        }
        
        int left = 0;
        left = root->left?_sumNumbers(root->left, num):left;
        int right = 0;
        right = root->right?_sumNumbers(root->right, num):right;
        return  left+right;  
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        return _sumNumbers(root, "");


    }
};