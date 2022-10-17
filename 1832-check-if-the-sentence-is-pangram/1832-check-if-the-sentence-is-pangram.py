class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        d  = dict()
        
        for i in sentence:
            if i not in d:
                d[i] = 1
            else:
                d[i] += 1
        
        return len(d) == 26;