class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        ans = []
        d = {}
        n = len(nums)
        for i in range(n):
            d[nums[i]] = i

        for i in range(n):
            if (target - nums[i]) in d.keys() and i != d[(target - nums[i])]:
                ans.append(i)
                ans.append(d[target-nums[i]])
                break
        return ans
        
        