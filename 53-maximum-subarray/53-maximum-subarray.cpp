class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int temp = nums[0];
        int maxSum = nums[0];
        int n = nums.size();
        for(int i=1;i<n;i++){
            temp = max(nums[i],temp+nums[i]);
            maxSum = max(maxSum,temp);
        }
        return maxSum;
        
    }
};