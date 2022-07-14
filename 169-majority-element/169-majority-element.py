class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        
        n = len(nums)//2
        ans = 1
        d = {}
        
        for i in nums:
            if i not in d.keys():
                d[i] = 1
            else:
                d[i] += 1
                if d[i]>n: 
                    ans = i
        return ans
            
        