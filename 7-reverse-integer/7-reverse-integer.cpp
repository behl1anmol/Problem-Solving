class Solution {
public:
    int reverse(int x) {
        long long int num = x;
        long long int ans = 0;
        
        while(num){
            ans = ans*10 + num%10;
            num = num/10;
        }
        
        if(ans < INT_MIN || ans > INT_MAX) return 0;
        return ans;
    }
};