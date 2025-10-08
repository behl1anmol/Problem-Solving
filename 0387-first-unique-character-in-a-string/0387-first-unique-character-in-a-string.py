class Solution:
    def firstUniqChar(self, s: str) -> int:
        
        d = dict()
        ans = -1
        for i in s:
            if i not in d.keys():
                d[i] = 1
            else:
                d[i] += 1
   
        for i in d.keys():
            if d[i] == 1:
                ans = s.index(i)
                break
        return ans
        