class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 and not(n & (n - 1)) and ((n & 1431655765) == n);    }
};