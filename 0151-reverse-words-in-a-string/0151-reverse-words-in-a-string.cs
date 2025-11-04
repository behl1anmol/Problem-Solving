public class Solution {
    public string ReverseWords(string s) {
        var arr = s.Trim().Split(' ')
                .Where(w => !string.IsNullOrWhiteSpace(w))
                .Reverse()
                .ToArray();
        return string.Join(" ", arr);
                
    }
}