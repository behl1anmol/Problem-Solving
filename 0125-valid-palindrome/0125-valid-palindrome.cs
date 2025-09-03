public class Solution {
    public bool IsPalindrome(string s) {

        if(string.IsNullOrEmpty(s)) return true;

        var strbuilder = new StringBuilder();
        foreach(var ch in s)
        {
            var lwr = char.ToLower(ch);
            if((lwr >= 'a' && lwr <= 'z') || (lwr >= '0' && lwr <= '9'))
            {
                strbuilder.Append(lwr);
            }
        }

        int i = 0;
        int j = strbuilder.Length-1;

        while(i<=j)
        {
            if(strbuilder[i]!=strbuilder[j]) return false;
            i++;j--;
        }

        return true;    
    }
}