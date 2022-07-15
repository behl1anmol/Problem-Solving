class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        ans = []
        n = len(nums)//3
        d = {}
        for i in nums:
            if i not in d.keys():
                d[i] = 1
            else:
                d[i] += 1
        for i in d.keys():
            if d[i] > n:
                ans.append(i)
        return ans