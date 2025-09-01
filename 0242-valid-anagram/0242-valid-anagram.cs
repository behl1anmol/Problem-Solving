public class Solution {
    public bool IsAnagram(string s, string t) {
        Dictionary<char, int> dict= new Dictionary<char, int>();

        int n1 = s.Count();

        for(int i=0; i< n1; i++)
        {
            if(dict.ContainsKey(s[i])) dict[s[i]]++;
            else dict[s[i]] = 1;
        }

        foreach(var i in t)
        {
            if(!dict.ContainsKey(i)) return false;
            else dict[i]--;
        }

        if(dict.Any(d => d.Value != 0)) return false;
        return true;
    }
}