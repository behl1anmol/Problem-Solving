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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newRoot = new TreeNode(val, root, NULL);
            return newRoot;
        }
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty() && depth>2){
            depth--;
            //cout<<depth;
            int count = q.size();

            while(count--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

        }
       /* cout<<q.size()<<endl;
        while(!q.empty()){
            TreeNode* temp = q.front();
            cout<<temp->val<<endl;
            q.pop();
        }*/
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            TreeNode* newLeft = new TreeNode(val);
            if(node->left){
                newLeft->left = node->left;
            }
            TreeNode* newRight = new TreeNode(val);
            if(node->right){
                newRight->right = node->right;
            }
            node->left = newLeft;
            node->right = newRight;
        }
        
        return root;

    }
};