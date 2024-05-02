class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n-1;
        
        sort(nums.begin(), nums.end());
        
        while(i<j){
            if(nums[i] + nums[j] == 0) return nums[j];
            else if(nums[i] + nums[j] < 0) i++;
            else j--;
        }

        return -1;
    }
};