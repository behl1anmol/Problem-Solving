class Solution {
public:
    bool isValid(string s) {
        
        int n = s.length();
        cout<<n;
        
        if(n==1) return false;
        //if(s[0]==')' || s[0]=='}' || s[0]==']') return false;
        //if(s[n-1]=='(' || s[n-1]=='[' || s[n-1]=='{') return false;
        
        stack<char> st;
        
        for(int i=0;i<n;i++){
            
            switch(s[i]){
                    
                case '(':
                    st.push('(');
                    break;
                case '{':
                    st.push('{');
                    break;
                case '[':
                    st.push('[');
                    break;
                case '}':
                    if(st.empty() || st.top()!='{') return false;
                    st.pop();
                    break;
                case ']':
                    if(st.empty() || st.top()!='[') return false;
                    st.pop();
                    break;
                case ')':
                    if(st.empty() || st.top()!='(') return false;
                    st.pop();
                    break;
            }
            
        }
        
        if(!st.empty()) return false;
        return true;
        
        
    }
};