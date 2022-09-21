class Solution {
public:
    
    int calculate_sum(vector<int> nums){
        
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)
                sum += nums[i];
        }
        return sum;
    }
    
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        
        
        int n = nums.size();
        int q = queries.size();
        vector<int> ans;
        int sum = calculate_sum(nums);
        
        //val idx
        for(int i=0; i<n; i++){
            int val = queries[i][0], idx = queries[i][1];
            int preVal = nums[idx];
            
            
            nums[idx] += val;
            
            bool EvenBefore = (preVal %2)==0;
            bool EvenNow = (nums[idx]%2==0);
                
            
            if(EvenBefore && EvenNow){
                sum = sum + val;
            }
            else if (!EvenBefore && EvenNow){
                sum = sum + nums[idx];
            }
            else if(EvenBefore && !EvenNow){

                sum = sum - preVal;
            }

            ans.push_back(sum);

        }
        
        return ans;
        
        
    }
};