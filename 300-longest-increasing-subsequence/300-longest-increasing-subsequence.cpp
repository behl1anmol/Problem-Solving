class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            auto it = lower_bound(ans.begin(), ans.end(), nums[i]);
            
            if(it==ans.end()) ans.push_back(nums[i]);
            else *it = nums[i];
        }
        return ans.size();
    }
};