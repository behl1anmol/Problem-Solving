class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && !(n&(n-1)) && !((n-1)%3);   
    }
};