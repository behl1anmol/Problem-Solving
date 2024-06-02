class Solution {
public:
    void CombinationalSum(int idx, int sum, vector<int> arr, vector<int>& ds,
                          vector<vector<int>>& ans) {
        if (sum == 0) {
            ans.push_back(ds);
            return;
        } else if (idx >= arr.size() || sum < 0) {
            return;
        } else {
            // pick
            ds.push_back(arr[idx]);
            CombinationalSum(idx, sum - arr[idx], arr, ds, ans);
            ds.pop_back();
            // not pick
            CombinationalSum(idx + 1, sum, arr, ds, ans);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        CombinationalSum(0, target, candidates, ds, ans);
        return ans;
    }
};