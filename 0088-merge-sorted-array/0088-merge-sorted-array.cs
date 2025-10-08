public class Solution {
    private void CountNums(int[] nums, SortedDictionary<int,int> dict, int len)
    {
        for(int i = 0;i<len;i++)
        {
            if(dict.ContainsKey(nums[i]))
            {
                dict[nums[i]] += 1;
            }
            else
            {
                dict[nums[i]] = 1;
            }
        }
    }
    public void Merge(int[] nums1, int m, int[] nums2, int n) {
        SortedDictionary<int,int> dict = new SortedDictionary<int,int>();
        var lenToDeduct = 0;
        var i = nums1.Length-1;
        while(i >= 0 && nums1[i--] == 0) lenToDeduct++;
        CountNums(nums1, dict, nums1.Length);
        CountNums(nums2, dict, nums2.Length);

        if(dict.ContainsKey(0))
        {
            dict[0]-=lenToDeduct;
        }

        int j = 0;
        foreach(var (k,v) in dict)
        {
            int t = v;
            while(t!=0)
            {
                nums1[j++] = k;
                t--;
            }
        }

    }
}