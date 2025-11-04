public class Solution {
    public int LengthOfLongestSubstring(string s) {
        int i = 0;
        var dict = new Dictionary<char,int>();
        int len = 0;

        for(int j = 0; j <s.Length ; j++)
        {
            if(!dict.ContainsKey(s[j])) dict.Add(s[j],j);
            else
            { 
                i = Math.Max(dict[s[j]] + 1, i);
                dict[s[j]] = j; 
            }
            //Console.WriteLine($"{i}:{j}");
            len = Math.Max((j-i)+1, len);
        }

        return len;
    }
}