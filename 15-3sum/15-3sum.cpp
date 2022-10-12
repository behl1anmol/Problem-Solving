class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<vector<int>> ans;
        
        for(int i=0;i<n-2;i++){
            int j = i+1;
            int k = n-1;
            
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    ans.insert({nums[i],nums[j],nums[k]});
                    j++;k--;
                }
                if(sum < 0) j++;
                if(sum > 0) k--;
            }
        }
        vector<vector<int>> arr(ans.begin(), ans.end());
        return arr;        
    }
};