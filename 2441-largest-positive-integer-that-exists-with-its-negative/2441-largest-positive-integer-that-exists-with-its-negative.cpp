class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        
        sort(nums.begin(), nums.end());
        
        if(nums[0] > 0) return -1;

        while(i<j){
            if(abs(nums[i]) == nums[j]) return nums[j];
            else if(abs(nums[i]) > nums[j]) i++;
            else j--;
        }

        return -1;
    }
};