public class Solution {
    public string Encode(string s)
    {
        int[] arr = new int[26];
        foreach(var c in s)
        {
            arr[c-'a'] += 1;
        }
        return string.Join(",", arr);
    }
    public IList<IList<string>> GroupAnagrams(string[] strs)
    {
        var dict = new Dictionary<string, List<string>>();

        foreach(var str in strs)
        {
            var encodedString = Encode(str);

            if(!dict.ContainsKey(encodedString))
            {
                dict.Add(encodedString, [str]);
            }
            else
            {
                dict[encodedString].Add(str);
            }
        }

        var res = new List<IList<string>>();
        foreach(var (key,val) in dict)
        {
            res.Add(val);
        }

        return res;
        
    }
}