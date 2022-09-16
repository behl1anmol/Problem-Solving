class Solution {
public:
    int maximumScoreUtils(vector<vector<int>>& dp, vector<int>& nums, vector<int>& multipliers, int i, int j, int n){
        
        if(j == multipliers.size()) return 0;
        
        if(dp[i][j]!=INT_MIN)
            return dp[i][j];
        
           dp[i][j] = max(maximumScoreUtils(dp,nums, multipliers, i+1, j+1, n) + (nums[i]*multipliers[j]) ,maximumScoreUtils(dp,nums, multipliers, i, j+1,n) + (nums[(n-1)-(j-i)]*multipliers[j]));
        return dp[i][j];
    }
    
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        
        int m = multipliers.size();
        vector<vector<int>>dp(m + 1, vector<int>(m+ 1, INT_MIN));
        
        return maximumScoreUtils(dp,nums, multipliers, 0, 0, nums.size());
    }
};