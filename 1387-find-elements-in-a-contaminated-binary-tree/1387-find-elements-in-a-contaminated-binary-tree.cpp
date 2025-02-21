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
class FindElements {
private:
    unordered_set<int> st;
public:
    FindElements(TreeNode* root) {
        if(root == NULL) return; 
        TreeNode* temp = root;
        temp->val = 0;
        st.insert(0);
        Recover(temp);
    }

    void Recover(TreeNode* root){
        if(root == NULL) return;
        int v = root->val;
        if(root->left)
        {   
            root->left->val = 2*v+1;
            st.insert(2*v+1);
        }
        if(root->right){
            root->right->val = 2*v+2;
            st.insert(2*v+2);
        }

        Recover(root->left);
        Recover(root->right);
    }
    
    bool find(int target) {
        return st.contains(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */