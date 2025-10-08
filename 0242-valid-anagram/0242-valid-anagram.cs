public class Solution {
    public bool IsAnagram(string s, string t) {
        s = new string(s.OrderBy(c => c).ToArray());
        t = new string(t.OrderBy(c => c).ToArray());

        return s.Equals(t);
    }
}