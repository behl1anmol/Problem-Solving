public class Solution {
    public int LengthOfLongestSubstring(string s) {

        var dict = new Dictionary<int,int>();
        var res = 0;
        var currRes = 0;
        var j = 0;
        var i = 0;

        for(i=0;i<s.Length;i++)
        {
            if(dict.ContainsKey(s[i]))
            {
                j = Math.Max(dict[s[i]]+1, j);
                dict[s[i]] = i;
            }
            else
            {
                dict.Add(s[i], i);
            }
            res = Math.Max(res, (i-j)+1);

        }
        return res;
    }
}

//dict-> a:1 b:2  
//aab
//i = 2 j = 1
//res = 1