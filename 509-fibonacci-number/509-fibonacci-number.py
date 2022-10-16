class Solution:
    def fib(self, n: int) -> int:
        
        @lru_cache(None)
        def sol(n):
            if n == 0: return 0
            if n == 1: return 1
            
            return sol(n-1) + sol(n-2)
        
        return sol(n)
            
        