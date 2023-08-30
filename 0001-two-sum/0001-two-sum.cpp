class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> hash;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            hash[nums[i]] = i;
        }
        
        for(int i=0;i<n;i++){
            int rem = target-nums[i];
            
            if(hash.find(rem)!=hash.end() && i!=hash[rem]){
                return {i,hash[rem]};
            }
        }
        
        return {};
        
    }
};