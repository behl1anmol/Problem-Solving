class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0

        for i in range(n):
            nums.sort()
            ele = min(nums[i:])
            if ele == 0:
                if nums.count(0) == n: return ans
                else: continue
            ans += 1
            for i in range(i,n):
                if nums[i] > 0:
                    nums[i] = nums[i] - ele
        return ans
                