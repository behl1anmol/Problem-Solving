class Solution:
    def sortColors(self, nums: List[int]) -> None:
        countArr = [0]*3
        for i in nums:
            countArr[i]+=1
        #print(countArr)
        j=0
        for i in range(len(countArr)):
            while countArr[i]>0:
                countArr[i]-=1
                nums[j] = i
                j+=1
                
        return nums
            
            
            
                
                
        """
        Do not return anything, modify nums in-place instead.
        """
        