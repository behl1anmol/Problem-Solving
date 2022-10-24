class Solution:
    ans = 0
    def unique(self, curr):
        
        d = Counter(curr)
        
        for i in d.elements():
            
            if d[i] > 1: return False;
        return True;
               
    def maxLength(self, arr: List[str]) -> int:
        
        #ans = 0
        
        def solution(arr, i, n,curr):
            if not self.unique(curr): return
            
            if i == n:
                self.ans = max(self.ans, len(curr))
                return
            
            solution(arr, i+1, n, curr+arr[i])
            solution(arr, i+1, n, curr)
        
        solution(arr, 0, len(arr), "")
        return self.ans
        
        
        
        