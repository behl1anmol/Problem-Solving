class Solution {
public:
    void CombinationalSum(int idx, int sum, vector<int>& ds, int k,
                          vector<vector<int>>& ans) {
        if(sum == 0 && ds.size() == k){
            ans.push_back(ds);
            return;
        }
        for(int i = idx; i<= 9; i++){

            if(i > sum || ds.size() > k) break;

            ds.push_back(i);
            CombinationalSum(i+1, sum-i,ds,k, ans);
            ds.pop_back();

        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        CombinationalSum(1, n,ds,k,ans );

        return ans;
    }
};