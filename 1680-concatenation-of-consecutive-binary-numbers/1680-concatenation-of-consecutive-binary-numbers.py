class Solution:
    def concatenatedBinary(self, n: int) -> int:
        s = ""
        for i in range(1,n+1):
            s = s + bin(i).replace("0b","")
        
        
        return int(s,2)%1000000007;
        
        
        
        