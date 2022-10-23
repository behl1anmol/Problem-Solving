class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        
        set<int> st(nums.begin(), nums.end());
        
        int s = accumulate(st.begin(), st.end(), 0);
        int arr_sum = accumulate(nums.begin(), nums.end(), 0);
        
        int sum = n*(n+1)/2;
        int r = arr_sum - s;
        int miss = sum - s; 
        
        return {r, miss};
    }
};