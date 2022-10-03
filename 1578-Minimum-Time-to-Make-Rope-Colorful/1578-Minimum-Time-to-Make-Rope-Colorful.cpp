class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = colors.size(); 
        int ans = 0;
        char balloon = colors[0];
        int idx = 0;
        for(int i=1;i<=n-1;i++){
            if(balloon==colors[i]){
                if(neededTime[idx] < neededTime[i]){
                    ans += neededTime[idx];
                    idx = i; balloon = colors[i];
                }
                else{
                    ans += neededTime[i];
                }
            }
            else{
                balloon = colors[i];
                idx = i;
            }
        }
        return ans;      
    }
};