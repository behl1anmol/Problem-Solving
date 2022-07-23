class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        int left = 0;
        int right = n-1;
        
        if(nums[left]!=nums[left+1])return nums[left];
        if(nums[right]!=nums[right-1]) return nums[right];
        
        while(left<right){   
            
            while(nums[left]==nums[left+1])left++;
            
            while(nums[right]==nums[right-1])right--;
            

            left++;right--;
            
            if(nums[left]!=nums[left+1])  return nums[left];
            
            if(nums[right]!=nums[right-1]) return nums[right];
            
        }
        return -1;
    }
};