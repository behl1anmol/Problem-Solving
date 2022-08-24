class Solution {
public:
    bool isPowerOfThree(int n) {
        double val = log10(n)/log10(3);
        return n>0 && val==int(val);
    }
};