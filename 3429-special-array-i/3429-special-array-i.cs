public class Solution {
    bool checkEvenParity(int[] nums)
    {
        for(int i = 0; i<nums.Length; i++)
        {
            if(i%2 == 0 && nums[i]%2!=0)
            {
                return false;
            }
            else if(i%2 != 0 && nums[i]%2 == 0)
            {
                return false;
            }
        }
        return true;
    }
    bool checkOddParity(int[] nums)
    {
        for(int i = 0; i<nums.Length; i++)
        {
            if(i%2 != 0 && nums[i]%2!=0)
            {
                return false;
            }
            else if(i%2 == 0 && nums[i]%2 == 0)
            {
                return false;
            }
        }
        return true;
    }
    public bool IsArraySpecial(int[] nums) 
    {
        //0 = even // 1 = odd
        //if nums[0] is even parity = 0 
        //if nums[0] is odd parity = 1

        return nums[0]%2 == 0? checkEvenParity(nums) : checkOddParity(nums);

    }
}