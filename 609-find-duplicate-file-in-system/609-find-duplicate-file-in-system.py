class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        d = {}
        
        
        for i in paths:
            temp = i.split(" ")
            dtry = temp[0]
            for j in range(1,len(temp)):
                s = temp[j]
                file, data = s[:s.index('(')],s[s.index('('):]
                if data not in d.keys():
                    d[data] = [dtry + '/' + file]
                else:
                    d[data].append(dtry + '/' + file)

        ans = []
        for i in d.keys():
            if len(d[i]) > 1:
                ans.append(d[i])
        
        return ans
        
                
                
                