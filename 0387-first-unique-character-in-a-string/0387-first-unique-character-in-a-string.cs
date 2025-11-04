public class Solution {
    public int FirstUniqChar(string s) {
        var c = s.GroupBy(chr => chr)
                 .Select(g => new {k = g.Key, v = g.Count()})
                 .Where(e => e.v == 1)
                 .FirstOrDefault()?.k??' ';
        if(c != ' ')
        {
            return s.IndexOf(c);
        }
        return -1;
    }
}