class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int candidate = nums[0];
        int votes = 1;
        
        for(int i=0; i<n; i++){
            if(nums[i]==candidate) votes++;
            else{
                if(nums[i]!=candidate) votes--;
                if(votes==0){
                    candidate = nums[i];
                    votes = 1;
                } 
            }
        }

        
        return candidate;
        
    }
};