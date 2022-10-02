class Solution:
    @lru_cache(None)
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        
        if n == 0 and target==0: return 1
        if n == 0 : return 0
            
        c = 0
        for i in range(1, k+1):
            if target >= i:  c = (c + self.numRollsToTarget(n-1, k, target-i)) % 1000000007
                    
        return c
        
    