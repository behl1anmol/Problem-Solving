public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        List<IList<int>> threeSum = new List<IList<int>>();
        Array.Sort(nums);


        for(int i=0;i<nums.Length-2;i++)
        {
            if(i > 0)
            {
                if(nums[i - 1] == nums[i])
                {
                    continue;
                }
            }
            int j = i+1;
            int k = nums.Length-1;
            while(j<k){
                var sum = nums[i] + nums[j] + nums[k];
                if(sum == 0){
                    var temp = new List<int>{nums[i],nums[j],nums[k]};
                    threeSum.Add(temp);
                }
                if (sum >= 0)
                    while(j < k && nums[k] == nums[--k]) { }
                if (sum <= 0)
                    while(j < k && nums[j] == nums[++j]) { }
            }
        }
        
        return threeSum;
        
    }
}