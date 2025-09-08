public class Solution {
    public int LengthOfLongestSubstring(string s) {
        var set = new HashSet<char>();
var n = s.Length;
var ans = 0;
var windowStart = 0;


for (var i = 0; i < n; i++)
{
        if (set.Contains(s[i]))
        {
            while (s[windowStart] != s[i])
            {
                set.Remove(s[windowStart]);
                windowStart++;
            }
            windowStart++;
        }
        else
        {
            set.Add(s[i]);
            ans = Math.Max(ans, i - windowStart + 1);
        }
    }
    return ans;
    }
}