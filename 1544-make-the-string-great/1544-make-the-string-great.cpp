class Solution {
public:
    string makeGood(string s) {
        if(s.size() <= 1) return s;
        string ans = s;
        int flag;
        
        while(flag != 0){
            flag = 0;
            for(int i=0;ans.size()>1 && i<=ans.size()-2;i++){
                if(ans[i] != ans[i+1] && (ans[i] == tolower(ans[i+1]) || ans[i] == toupper(ans[i+1]))){
                    ans.erase(ans.begin()+i);
                    ans.erase(ans.begin()+i);
                    flag = 1;
                }
            }
        }
        return ans;
        
        
    }
};