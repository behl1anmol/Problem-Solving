public class Solution {
    public string ReverseWords(string s)
    {
        var arr = s.Split(" ");
        var sb = new StringBuilder();
        for(int i = arr.Length-1; i >= 0; i--)
        {
            if(String.IsNullOrWhiteSpace(arr[i])) continue;
            sb.Append(arr[i]);
            sb.Append(" ");
        }

        return sb.ToString().Trim();
    }
}