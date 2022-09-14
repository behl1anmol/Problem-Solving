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
    
    int checkPseudoPalindrome(vector<int> arr){
        
        int odd = 0;

        for(auto i : arr){

            if(i%2 != 0) odd++;
        }
        if(odd>1) return 0;
        //cout<<endl<<endl;
        return 1;
        
    }
    
    
    int pseudoPalindromicPathsUtils(TreeNode* root, vector<int> arr, int ans){
        if(!root) return -1;
        
        
        arr[root->val]++;
        
        int left = pseudoPalindromicPathsUtils(root->left, arr, ans);

        int right = pseudoPalindromicPathsUtils(root->right, arr, ans);
        
        
        if(left == -1 && right == -1)
            ans += checkPseudoPalindrome(arr);
        
        return ans + (left==-1?0:left) + (right==-1?0:right);
    }
    
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int> arr(10,0);
        return pseudoPalindromicPathsUtils(root, arr, 0);
        
        
    }
};