public class Solution {
    public int MajorityElement(int[] nums) {
        return nums.GroupBy(n=>n).MaxBy(g=>g.Count()).Key;
    }
}