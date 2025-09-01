public class Solution {

    private string SortString(string s)
    {
        return new string(s.OrderBy(c=>c).ToArray());
    }

    // this is an O(N*KlogK) solution where k is largest string length
    public IList<IList<string>> GroupAnagramsUnoptimized(string[] strs) 
    {
        var newStrs = new List<string>(); 
        foreach(var s in strs)
            newStrs.Add(SortString(s));
        
        IList<IList<string>> ans = new List<IList<string>>();
        Dictionary<string, List<string>> dict = new Dictionary<string, List<string>>();
        for(int i=0;i<newStrs.Count();i++)
        {
            if(!dict.ContainsKey(newStrs[i]))
                dict[newStrs[i]] = new List<string>();
            
            dict[newStrs[i]].Add(strs[i]);
        }

        foreach(var (key, value) in dict)
        {
            ans.Add(value);
        }
        return ans;
    }

    //we can do it in O(n*k)
    public IList<IList<string>> GroupAnagrams(string[] strs)
    {
        Dictionary<string, List<string>> dict = new Dictionary<string, List<string>>();

        foreach(var str in strs)
        {
            int[] count = new int[26];
            foreach(var c in str)
                count[c - 'a']++;
            
            string key = string.Join("", count);
             if(!dict.ContainsKey(key))
                dict[key] = new List<string>();
            
            dict[key].Add(str);
        }
        return new List<IList<string>>(dict.Values);
    }
}