class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        
        ele = set()
        
        for i in range(0,len(sentence)):
            ele.add(sentence[i])

        return len(ele) == 26;