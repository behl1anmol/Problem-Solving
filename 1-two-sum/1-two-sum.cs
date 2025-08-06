#!/usr/bin/dotnet
public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        Dictionary<int, int> dict = new Dictionary<int, int>();

        for (int i = 0; i < nums.Count(); i++)
        {
            int rem = target - nums[i];
            if (dict.ContainsKey(rem))
            {
                return [i, dict[rem]];
            }
            dict[nums[i]] = i;
        }

        return [];
    }
}