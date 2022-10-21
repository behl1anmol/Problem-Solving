class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, vector<int>> mp;
        
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        
        for(auto it : mp){
            vector<int> idx = it.second;
            int m = idx.size();
            if(m <= 1)continue;
            
            for(int i=0;i<m-1;i++){
                if(abs(idx[i]-idx[i+1]) <= k) return true;
            }
        }
        return false;
        
    }
};