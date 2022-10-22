class Solution:
    def minWindow(self, s: str, t: str) -> str:
        
        if not t or not s:
            return ""
        
        d = {}
        for i in t:
            if i not in d.keys():
                d[i] = 1
            else: d[i] += 1
        
        #print(d)
        
        
        l,r = 0,0
        
        ans = (float("inf"),None,None)
        
        formed = 0
        n = len(d)
        #print(n)
        curr = {}
        
        while r < len(s):
            
            char = s[r]
            curr[char] = curr.get(char,0) + 1
            #print(curr)
            if char in d and curr[char] == d[char]:
                formed += 1
                #print("formed: ",formed)
            
            while l<=r and formed == n:
                temp = s[l]
                
                if r-l+1 < ans[0]:
                    #print("here",l,r)
                    ans = (r-l+1, l, r)
                #print(temp)
                curr[temp] -= 1
                if temp in d and curr[temp] < d[temp]:
                    formed -= 1
                    #print("inside formed:", formed)
                l+=1
            #print(r)
            r+=1
        #print(ans)
        return "" if ans[0] == float("inf") else s[ans[1]:ans[2]+1]
                    