class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
     
        
        int n = nums.size();
        if(n<3) return false;
        
        int first = INT_MAX, second = INT_MAX;
        
        for(auto it : nums){
            if(it <= first) first = it;
            else if(it <= second) second = it;
            else return true;
        }
        return false;
    }
};