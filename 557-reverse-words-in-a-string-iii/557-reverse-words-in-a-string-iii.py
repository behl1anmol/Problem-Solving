class Solution:
    def reverseWords(self, s: str) -> str:
        
        arr = s.split(" ")
        ans = ""
        
        for i in arr:
            ans = ans + i[-1::-1] + " "
        
        return ans.strip()
        