class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int _xor = 0;

        for (int n : nums) {
            _xor = _xor ^ n;
        }
        return __builtin_popcount(_xor ^ k);
    }
};