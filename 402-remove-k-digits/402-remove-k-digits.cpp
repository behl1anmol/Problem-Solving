class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.length();
        st.push(num[0]);

        for(int i=1;i<n;i++){
            while(k>0 && !st.empty() && st.top()>num[i]){
                k--;
                st.pop();
            }
            st.push(num[i]);
            
            //important condition to prevent TLE
            if(st.size() == 1 && num[i]== '0'){
                st.pop();
            }
        }
        
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans.length() == 0?"0":ans;
    }
};