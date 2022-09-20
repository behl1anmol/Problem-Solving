class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        
        strnum2 = ''.join([chr(i) for i in nums2])
        temp = ''
        ans = 0
        
        for i in nums1:
            temp += chr(i)
            
            if temp in strnum2:
                ans = max(ans,len(temp))
            else:
                temp = temp[1:]
        
        return ans
        