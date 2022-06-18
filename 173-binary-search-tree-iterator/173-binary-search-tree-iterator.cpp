class BSTIterator {
    
private:
    TreeNode* root;
    stack<pair<TreeNode*, int>> inorder;
    
    
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
        inorder.push({root,0});
    }
    
    int next() {

        if(!hasNext()){
            return -1;
        }

        pair<TreeNode*, int> *front;
        
        front = &inorder.top();
        
        while(
            ((*front).first->left && ((*front).second==0)) ||
            (((*front).first->left && (*front).first->right) && ((*front).second==0))
            ){
            
            if((*front).first->left){
                (*front).second = 1;
                inorder.push({(*front).first->left, 0});
                front = &inorder.top();
            }
            
        }


        if((*front).second == 1 || !((*front).first->left)){
            inorder.pop();
            int val = (*front).first->val;
            if((*front).first->right){
                inorder.push({(*front).first->right, 0});
                front = &inorder.top();
            }
            return val;
        }
        inorder.pop();
        return (*front).first->val;
            
            
    }
        
    
    bool hasNext() {
        if(!inorder.empty()) return true;
        return false;
    }
};