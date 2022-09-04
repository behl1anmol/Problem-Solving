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
    map<int, map<int, multiset<int>>> mp;
    
    void calculateVerticalOrder(TreeNode* root, int distance, int level){
        
        mp[distance][level].insert(root->val);
        if(root->left) calculateVerticalOrder(root->left, distance-1, level+1);
        if(root->right) calculateVerticalOrder(root->right, distance+1, level+1);
        
        
    }
    
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        calculateVerticalOrder(root, 0, 0);
        
        for(auto const& item : mp){
            vector<int> temp;
            for(auto const& j : item.second)
                temp.insert(temp.end(),j.second.begin(), j.second.end());
            ans.push_back(temp);
        }
        
        return ans;
    }
};