class Solution {
public:
    int CombinationalSum(int idx, int sum, vector<int> arr, vector<int>& dp) {
        if (sum == 0) {
            return 1;
        }
        if (sum < 0)
            return 0;

        if (dp[sum] != -1)
            return dp[sum];

        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (sum >= arr[i]) {
                count += CombinationalSum(i, sum - arr[i], arr, dp);
            }
        }
        return dp[sum] = count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return CombinationalSum(0, target, nums, dp);
    }
};