class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        
        s = s.strip()
        arr = list(s.split(" "))
        
        return len(arr[-1])
        