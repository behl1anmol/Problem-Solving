public class Solution {

    public bool IsValid(string s) {
        var st = new Stack<char>();

        for(int i=0;i<s.Length;i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.Push(s[i]);
            }
            else
            {
                if(st.Count() == 0) return false;
                var top = st.Pop();
                if ((s[i] == ')' && top != '(') ||
                    (s[i] == '}' && top != '{') ||
                    (s[i] == ']' && top != '['))
                {
                    return false;
                }
            }
        }
        return st.Count() == 0;
    }
}