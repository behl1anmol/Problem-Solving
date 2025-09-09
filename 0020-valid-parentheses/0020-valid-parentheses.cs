public class Solution {
    public bool IsValid(string s) {
        if(s.Length == 1) return false;
        var st = new Stack<char>();

        foreach(var ch in s)
        {
            switch(ch)
            {
                case '(':
                    st.Push(ch);
                    break;
                case ')':
                    if(st.Any() && st.Peek() == '(') st.Pop();
                    else st.Push(ch);
                    break;
                case '{':
                    st.Push(ch);
                    break;
                case '}':
                    if(st.Any() && st.Peek() == '{') st.Pop();
                    else st.Push(ch);
                    break;
                case '[':
                    st.Push(ch);
                    break;
                case ']':
                    if(st.Any() && st.Peek() == '[') st.Pop();
                    else st.Push(ch);
                    break;
            }
        }
        return !st.Any();
    }
}