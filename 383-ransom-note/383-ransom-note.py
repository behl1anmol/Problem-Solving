class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        
        freq = {}
        
        for i in ransomNote:
            if i not in freq.keys():
                freq[i] = 1
            else:
                freq[i] += 1
                
        for i in magazine:
            if i in freq.keys(): freq[i] -= 1
            
        for i in freq.keys():
            if freq[i]>0:
                return False
        return True;
        