class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int n = nums.size();
        int sum = nums[0];
        int maxSum = nums[0];
        
        for(int i=1;i<n;i++){
            sum = max(nums[i], sum+nums[i]);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};