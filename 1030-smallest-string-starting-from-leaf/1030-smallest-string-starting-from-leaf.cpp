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
    char hash[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n'
                    ,'o','p','q','r','s','t','u','v','w','x','y','z'};

    void _smallestFromLeaf(TreeNode* root, string path, string &smallest){
        
        if(!root) return ;

        path = hash[root->val] + path;

        if(!root->left && !root->right){
            smallest = min(smallest, path);
        }

        _smallestFromLeaf(root->left, path, smallest);
        _smallestFromLeaf(root->right, path, smallest);
    }
    string smallestFromLeaf(TreeNode* root) {
        string smallest = "~";
        _smallestFromLeaf(root,"", smallest);
        return smallest;
    }
};