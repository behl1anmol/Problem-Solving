class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        ver1 = version1.split(".")
        ver2 = version2.split(".")
        
        while len(ver1) > len(ver2):
            ver2.append("0")
            
        while len(ver2) > len(ver1):
            ver1.append("0") 
        
        ans = 0
        
        for (i,j) in zip(ver1, ver2):
            if int(i) < int(j):
                ans = -1
                break
            elif int(i) > int(j):
                ans = 1
                break
        return ans
            