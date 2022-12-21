class Solution:
    def isPalindrome(self, s, l, r, maxLen,i1,i2):
        n = len(s)
        while l>=0 and r<n and s[l] == s[r]:
            if (r-l+1) > maxLen:
                maxLen = r-l+1
                i1,i2 = l,r
            l -= 1
            r += 1
        return maxLen, i1, i2

    def longestPalindrome(self, s: str) -> str:
        ans = ""
        i1,i2 = 0,0
        maxLen = 0
        n = len(s)
        for i in range(n):
            #odd palindrome
            maxLen, i1,i2 = self.isPalindrome(s, i, i, maxLen, i1, i2)
            #even palindrome
            maxLen, i1,i2 = self.isPalindrome(s, i, i+1, maxLen, i1, i2)
        return s[i1:i2+1]
            
        