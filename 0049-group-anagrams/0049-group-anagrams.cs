public class Solution {

    private string SortString(string s)
    {
        return new string(s.OrderBy(c=>c).ToArray());
    }

    public IList<IList<string>> GroupAnagrams(string[] strs) 
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
}