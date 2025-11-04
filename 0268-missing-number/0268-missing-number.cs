public class Solution {
    public int MissingNumber(int[] nums) {
        var n = nums.Length;
        var expSum = n*(n+1)/2;
        
        var actSum = expSum - nums.Sum();
        return actSum;
    }
}