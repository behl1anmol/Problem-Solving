class Solution {
public:
    
    int numDecodings(string s) {
        
        if(s[0]=='0') return 0;
        if(s.size()==1) return 1;

        int ptp = 1, p=1;

        for(int i=1;i<s.size();i++){
            int d = s[i]-'0';
            int dd = (s[i-1]-'0')*10+d;
            int curr = 0;

            if(d>0) curr = curr+p;
            if(dd>=10 && dd<=26) curr = curr+ptp;

            ptp=p;
            p=curr;

        }
        return p;


    }
};