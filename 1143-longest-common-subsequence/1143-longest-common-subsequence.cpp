class Solution {
public:
    /* top-down DP
    
        int LCS(string text1, string text2, int idx1, int idx2, vector<vector<int>>& dp){
        
        if(idx1<0||idx2<0) return 0;
        
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        
        if(text1[idx1] == text2[idx2]){
            return dp[idx1][idx2] = 1 + LCS(text1, text2, idx1-1, idx2-1, dp);
        }
        return dp[idx1][idx2] = max(LCS(text1, text2, idx1, idx2-1, dp), LCS(text1, text2, idx1-1, idx2, dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int idx1 = text1.size();
        int idx2 = text2.size();
        
        vector<vector<int>> dp(idx1,vector<int>(idx2,-1));
        
        return LCS(text1, text2, idx1-1, idx2-1, dp);
        
    }*/
    
    //Bottom-up DP
      
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        
                
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        
        for(int i=0;i<=m;i++) dp[0][i] = 0;
        
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                if(text1[idx1-1] == text2[idx2-1])
                    dp[idx1][idx2] = 1+ dp[idx1-1][idx2-1];
                else
                    dp[idx1][idx2] = max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
            }
        }
        
        return dp[n][m];
        
    }
};