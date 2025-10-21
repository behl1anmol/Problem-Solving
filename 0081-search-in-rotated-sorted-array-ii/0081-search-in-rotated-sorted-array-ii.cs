public class Solution {
    public bool Search(int[] nums, int target, int l, int r)
    {
        var mid = l +(r-l)/2;

        while(l<=r)
        {
            if(nums[mid] == target) return true;

            if(nums[mid] == nums[l])
            {
                return Search(nums, target, l, mid-1) || Search(nums, target, mid+1, r);
            }
            else if(nums[mid] > nums[l])
            {
                if(nums[l] <= target && target < nums[mid])
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
                if(nums[mid] < target && nums[r] >= target)
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

        return false;
    }
    public bool Search(int[] nums, int target) {
        var l = 0;
        var r = nums.Length-1;
        return Search(nums, target, l, r);
    }
}