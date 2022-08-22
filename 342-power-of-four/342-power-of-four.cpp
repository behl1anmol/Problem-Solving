class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0) return false;
        
        long long int c = 1;
        while(c<n){
            c=c*4;
        }
        if(c==n) return true;
        return false;
    }
};