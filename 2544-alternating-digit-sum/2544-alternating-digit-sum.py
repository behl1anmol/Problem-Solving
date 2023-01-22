class Solution:
    def alternateDigitSum(self, n: int) -> int:
        num = list(map(int,str(n)))
        even_sum = sum(num[0::2])
        odd_sum = sum(num[1::2])
        
        return even_sum-odd_sum;
        
        
        