public class Solution {
    public int FindMin(int[] nums) {
        int res = nums[0];
        int l = 0;
        int r = nums.Length-1;

        while(l<=r)
        {
            if(nums[l] < nums[r])
            {
                res = Math.Min(res, nums[l]);
                break;
            }

            int mid = l + (r-l)/2;
            res = Math.Min(nums[mid],res);

            if(nums[mid] >= nums[l]) l = mid+1;
            else r = mid-1;
        }
        return res;
    }
}