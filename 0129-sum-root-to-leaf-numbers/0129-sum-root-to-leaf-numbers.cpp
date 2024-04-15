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
    int tree_height(TreeNode* root) {
        if (root == NULL)
            return 0;
        else {
            int left_height = tree_height(root->left);
            int right_height = tree_height(root->right);
            return std::max(left_height, right_height) + 1;
        }
    }

    int _sumNumbers(TreeNode* root, string num){
        
        //num = num + root->val*pow(10,h);
        num = num + to_string(root->val);
        //cout<<num<<endl;

        if(!root->left && !root->right){
            //reverse(num.begin(), num.end());
            int numi = stoi(num); 
            return numi;
        }
        
        int left = 0;
        left = root->left?_sumNumbers(root->left, num):left;
        cout<<"left:"<<left;
        int right = 0;
        right = root->right?_sumNumbers(root->right, num):right;
        cout<<" right:"<<right<<endl;
        return  left+right;  
    }
    int sumNumbers(TreeNode* root) {
        int height = tree_height(root);
        cout<<height<<endl;
        if(height == 0) return 0;
        if(height == 1) return root->val;

        stack<int> st;

        return _sumNumbers(root, "");


    }
};