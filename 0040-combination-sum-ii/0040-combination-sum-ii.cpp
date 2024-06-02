class Solution {
public:
    void CombinationalSum(int idx, int sum, vector<int> arr, vector<int>& ds,
                          vector<vector<int>>& ans) {
        if(sum == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = idx; i<arr.size(); i++){
            if(i > idx && arr[i] == arr[i-1]) continue;

            if(arr[i] > sum) break;

            ds.push_back(arr[i]);
            CombinationalSum(i+1, sum-arr[i], arr,ds,ans);
            ds.pop_back();

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;

        sort(candidates.begin(), candidates.end());
        CombinationalSum(0, target, candidates, ds, ans);

        return ans;
    }
};