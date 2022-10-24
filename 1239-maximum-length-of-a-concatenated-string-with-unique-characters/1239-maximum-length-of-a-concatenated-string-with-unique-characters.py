class Solution:
    ans = 0
    def unique(self, curr):
        
        d = Counter(curr)
        
        for i in d.elements():
            
            if d[i] > 1: return False
        return True
    
    def listToTuple(function):
        def wrapper(*args):
            args = [tuple(x) if type(x) == list else x for x in args]
            result = function(*args)
            result = tuple(result) if type(result) == list else result
            return result
        return wrapper
    
    @listToTuple
    @lru_cache(None)
    def maxLength(self, arr: List[str]) -> int:
        
        def solution(arr, i, n,curr):
            if not self.unique(curr): return
            
            if i == n:
                self.ans = max(self.ans, len(curr))
                return
            
            solution(arr, i+1, n, curr+arr[i])
            solution(arr, i+1, n, curr)
        
        solution(arr, 0, len(arr), "")
        return self.ans
        
        
        
        