public class Solution {
    public int Search(int[] nums, int target) {
        var l = 0;
        var r = nums.Length-1;
        var mid = l +(r-l)/2;

        while(l<=r)
        {
            if(nums[mid] == target) return mid;

            if(nums[mid] >= nums[l])
            {
                if(nums[l] <= target & target < nums[mid])
                {
                    r = mid -1;
                }
                else
                {
                    l = mid+1;
                }
            }
            else
            {
                if(nums[mid] <= target && nums[r] > target)
                {
                    l = mid+1;
                }
                else
                {
                    r = mid - 1;
                }
            }

            mid = l + (r-l)/2;
        }

        return -1;
    }
}