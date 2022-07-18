class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int> m;
        vector<int> v;
        
        for(int i=0;i<nums.size();i++){
                        
            int c = target - nums[i];
            if(m.find(c) != m.end()){
                v.push_back(i);
                v.push_back(m[c]);
                return v;
            }
            m[nums[i]] = i;
             
        }
        return v;
    }
};