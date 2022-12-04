class Solution {
public:
    int myAtoi(string s) {
        int flag = 0;
        int i = 0;
        int n = s.size();
        unsigned long long number = 0;
        
        //skipping spaces
        for(;i<n;){
            if(s[i] == ' ') i++;
            if(s[i] != ' ') break;
        }

        //checking for '+'/'-'
        if(!isdigit(s[i])){
            if(s[i] == '-') flag = 1;
            else if(s[i] != '+') return number;
            i++;
        }
        
        while(s[i] == '0') i++;
        
        //checking for digit
        int dig = 0;
        while(dig < 11 && i<n && isdigit(s[i])){
            number = number*10 + (s[i] - '0');
            i++;
            dig++;
        }
        
        if(number > INT_MAX) return flag == 1? INT_MIN : INT_MAX;

        return flag == 1? -number : number;
        
    }
};