class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        
        ans = []
        if(len(changed)%2==1): return ans
        
        changed.sort()
        dic = {}
        
        for i in changed:
            if i in dic.keys():
                dic[i]+=1
            else:
                dic[i] = 1

        for i in changed:
            if dic[i]==0: continue
            if (2*i) not in dic.keys() or dic[2*i]==0: return []
            ans.append(i)
            dic[i] -=1
            dic[2*i] -= 1
 
        return ans
        