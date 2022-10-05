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
    queue<TreeNode*> addOneRowUtils(TreeNode* root, int depth){
        queue<TreeNode*> q;

        q.push(root);
        depth--;
        while(depth>0){
            
            int n  = q.size();

            for(int i=0;i<n;i++){
                TreeNode* top = q.front();
                q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            depth--;
        }
        return q;
    }    


    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newRoot = new TreeNode(val,root,NULL);
            
            return newRoot;
        }
        queue<TreeNode*>q = addOneRowUtils(root, depth-1);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            TreeNode* newLeft = new TreeNode(val, front->left, NULL);
            TreeNode* newRight = new TreeNode(val, NULL, front->right);

            front->left = newLeft;
            front->right = newRight;
        }
        return root;
    }
};