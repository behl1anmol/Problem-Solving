class Solution {
public:
    const int mod = 1000000007;
    vector<vector<int>> dp{31,vector<int>(1001,-1)};

    int numRollsToTarget(int n, int k, int target) {
        if(n==0 && target==0) return 1;
        if(n==0) return 0;
        if(target==0) return 0;

        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int ans=0;

        for(int i=1;i<=k;i++){
            if(i<=target) ans = (ans + numRollsToTarget(n-1,k,target-i))%mod;
        }
        return dp[n][target] = ans;
    }
};