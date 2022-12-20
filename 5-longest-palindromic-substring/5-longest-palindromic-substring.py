class Solution:
    def isPalindrome(self, s, l, r, maxLen,ans):
        pal = ans
        n = len(s)
        while l>=0 and r<n and s[l] == s[r]:
            if (r-l+1) > maxLen:
                maxLen = r-l+1
                pal = s[l:r+1]
            l -= 1
            r += 1
        return maxLen,pal

    def longestPalindrome(self, s: str) -> str:
        ans = ""
        maxLen = 0
        n = len(s)
        for i in range(n):
            #odd palindrome
            maxLen, ans = self.isPalindrome(s, i, i, maxLen,ans)
            #even palindrome
            maxLen, ans = self.isPalindrome(s, i, i+1, maxLen, ans)
        return ans
            
        