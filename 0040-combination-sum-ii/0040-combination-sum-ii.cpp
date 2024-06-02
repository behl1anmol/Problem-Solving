class Solution {
public:
    void CombinationalSum(int idx, int sum, vector<int> arr, vector<int>& ds,
                          set<vector<int>>& ans) {
        if (sum == 0) {
            ans.insert(ds);
            return;
        } else if (idx >= arr.size() || sum < 0) {
            return;
        } else {
            // pick
            ds.push_back(arr[idx]);
            CombinationalSum(idx+1, sum - arr[idx], arr, ds, ans);
            ds.pop_back();
            // not pick
            CombinationalSum(idx + 1, sum, arr, ds, ans);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        set<vector<int>> ans;

        int sum = accumulate(candidates.begin(), candidates.end(),0);
        if(sum < target){
            vector<vector<int>> v(ans.begin(), ans.end());
            return v;
        }

        sort(candidates.begin(), candidates.end());
        CombinationalSum(0, target, candidates, ds, ans);

        vector<vector<int>> v(ans.begin(), ans.end());
        return v;
    }
};