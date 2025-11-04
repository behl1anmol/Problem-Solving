public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        var dct = new Dictionary<int, int>();

        for(int i = 0; i < nums.Length; i++)
        {
            int rem = target-nums[i];

            if(!dct.ContainsKey(rem))
            {
                dct[nums[i]] = i;
            }
            else
            {
                return new int[2]{i, dct[rem]};
            }
        }
        return new int[]{};
    }
}