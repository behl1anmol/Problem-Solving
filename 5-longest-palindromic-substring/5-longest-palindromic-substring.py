class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = ""
        maxLen = 0
        n = len(s)
        for i in range(n):
            #odd palindrome
            l, r = i,i
            while l>=0 and r<n and s[l] == s[r]:
                if (r-l+1) > maxLen:
                    maxLen = r-l+1
                    ans = s[l:r+1]
                l -= 1
                r += 1
            #even palindrome
            l,r = i, i+1
            while l>=0 and r<n and s[l] == s[r]:
                if(r-l+1) > maxLen:
                    maxLen = r-l+1
                    ans = s[l:r+1]
                l -= 1
                r += 1
        return ans
            
        