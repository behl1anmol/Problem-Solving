public class Solution {
    public bool IsPalindrome(string s) {
        StringBuilder sb = new StringBuilder();

        foreach(var ch in s)
        {
            if(char.IsLetterOrDigit(ch))
            {
                sb.Append(Char.ToLower(ch));
            }
        }
        int left = 0;
        int right = sb.Length-1;
        while(left < right)
        {
            if(sb[left] != sb[right]) return false;
            left++;
            right--;
        }
        return true;
        
    }
}