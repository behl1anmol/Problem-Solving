public class Solution {
    //bias = 1 means left, 0 means right
    public int SearchRange(int[] nums, int target, bool bias)
    {
        var  l = 0;
        var r = nums.Length - 1;
        int index = -1;
        while(l <= r)
        {
            var mid = l + (r-l)/2;
            if(nums[mid] == target)
            {
                index = mid;
                if(bias) r = mid-1;
                else l = mid+1;
            }
            else if(target < nums[mid]) r = mid- 1;
            else l = mid + 1;
        }
        return index;
    }
    public int[] SearchRange(int[] nums, int target) {
        return new int[]{SearchRange(nums, target, true), SearchRange(nums, target, false)};      
    }
}