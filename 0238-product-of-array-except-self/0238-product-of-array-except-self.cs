public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        int n = nums.Length;
        int[] prefix = new int[n]; 
        int[] suffix = new int[n];
        int[] ans = new int[n];

        prefix[0] = nums[0];
        for(int i=1; i<n; i++)
        {
            prefix[i] = prefix[i-1] * nums[i];
        }

        suffix[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--)
        {
            suffix[i] = suffix[i+1] * nums[i];
        }

        for(int i=0; i<n; i++)
        {
            var prefix_m = (i==0? 1 : prefix[i-1]);
            var suffix_m = (i==(n-1)? 1 : suffix[i+1]);
            ans[i] = prefix_m * suffix_m;
        }

        return ans;
    }
}