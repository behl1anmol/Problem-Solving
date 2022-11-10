class Solution:
    def removeDuplicates(self, s: str) -> str:
        
        st = []
        
        for i in s:   
            if st and st[-1] == i:
                st.pop()
            else:
                st.append(i)
        return ''.join(st)
            
            
        