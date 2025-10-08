public class Solution {
    public int MaxSubArray(int[] nums) {
        int currSum = nums[0];
        int maxSum = nums[0];

        for(int i = 1; i<nums.Length; i++)
        {
            currSum = currSum + nums[i] < nums[i]? nums[i]: currSum+nums[i];
            maxSum = Math.Max(currSum, maxSum);
        }
        return maxSum;
    }
}