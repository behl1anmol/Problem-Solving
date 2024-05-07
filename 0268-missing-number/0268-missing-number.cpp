class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int arr_sum = 0;
        int n = nums.size();
        for(int i:nums) arr_sum+=i;
        
        int expected_sum = n*(n+1)/2;
        
        return expected_sum - arr_sum;
    }
};