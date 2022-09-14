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
        //cout<<"count: "<<c<<endl;
        for(auto i : arr){
            //cout<<key<<":" <<value<<endl;
            if(i%2 != 0) odd++;
        }
        if(odd>1) return 0;
        //cout<<endl<<endl;
        return 1;
        
    }
    
    
    int pseudoPalindromicPathsUtils(TreeNode* root, vector<int> arr, int ans){
        if(!root) return -1;
        
        
        arr[root->val]++;
        
        /*cout<<"printing map:"<<endl;
        for(auto &[key,value] : mp){
            cout<<"key:"<<key<<" value:"<<value<<endl;
        }*/
        
        int left = pseudoPalindromicPathsUtils(root->left, arr, ans);
        //cout<<"left:"<<left<<endl;
        int right = pseudoPalindromicPathsUtils(root->right, arr, ans);
        //cout<<"right:"<<right<<endl;
        
        
        if(left == -1 && right == -1)
            ans += checkPseudoPalindrome(arr);
        //cout<<"ans:"<<ans<<endl;
        
        return ans + (left==-1?0:left) + (right==-1?0:right);
    }
    
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int> arr(10,0);
        return pseudoPalindromicPathsUtils(root, arr, 0);
        
        
    }
};