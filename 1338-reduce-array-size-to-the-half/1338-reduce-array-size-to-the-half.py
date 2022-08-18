class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        
        d = {}
        for i in arr:
            if i not in d.keys():
                d[i] = 1
            else:
                d[i] = d[i] + 1
        d = dict(sorted(d.items(), key = lambda item:item[1], reverse=True))
        
        ans = 0
        n = len(arr)
        half = n//2

        for i in d.keys():
            n = n - d[i]
            ans = ans + 1
            if n <= half:
                break;
        
        return ans