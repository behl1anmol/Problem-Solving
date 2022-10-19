class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        d = {}
        
        for i in words:
            if i not in d.keys():
                d[i] = 1
            else:
                d[i] += 1
                
                
        arr = sorted(d.items(), key=lambda a: (-a[1], a[0]))
        
        ans = []
        for i in arr:
            if k==0: break
            ans.append(i[0])
            k-=1
            
        return ans