public class Solution {
    public bool IsValid(string s) {
        var st = new Stack<char>();
        st.Push(s[0]);

        for(int i=1;i<s.Length;i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.Push(s[i]);
            }
            else if(s[i] == '}')
            {
                if(!st.Any()) return false;
                else if(st.Peek() == '{') st.Pop();
            }
            else if(s[i] == ')')
            {
                if(!st.Any()) return false;
                else if(st.Peek() == '(') st.Pop();
            }
            else
            {
                if(!st.Any()) return false;
                else if(st.Peek() == '[') st.Pop();
            }
        }
        return st.Count() == 0;
    }
}