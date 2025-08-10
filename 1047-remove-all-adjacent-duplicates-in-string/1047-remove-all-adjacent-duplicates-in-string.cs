public class Solution {
    public string RemoveDuplicates(string s) {
        Stack<char> stack = new Stack<char>();
        //stack.Push(s[0]);
        
        foreach(var c in s)
        {
            if(stack.Any() && stack.Peek() == c)
            {
                while(stack.Any() && stack.Peek() == c)
                {
                    stack.Pop();
                }
            }
            else
            {
                stack.Push(c);
            }
        }
        string ans = "";
        while(stack.Any())
        {
            ans = stack.Pop() + ans;
        }

        return ans;
    }
}