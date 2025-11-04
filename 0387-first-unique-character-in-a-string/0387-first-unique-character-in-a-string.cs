public class Solution {
    public int FirstUniqChar(string s) {
        var hash = new Dictionary<char, int>();
        var ct = new Dictionary<char, int>();

        for(int i = 0; i < s.Length; i++)
        {
            if(!hash.ContainsKey(s[i]))
            {
                hash[s[i]] = i;
            }
            if(!ct.ContainsKey(s[i]))
                ct[s[i]] = 1;
            else
                ct[s[i]]+=1;
        }
        
        int res = s.Length+1;
        foreach(var (key,val) in ct)
        {
            if(val == 1)
            {
                return hash[key];
            }
        }

        return res == s.Length+1 ? -1:res;
    }
}