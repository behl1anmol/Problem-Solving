class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        unordered_map<int,int> count;
        unordered_map<int,int> req;
        
        //calculate count of freq for each element
        for(auto n:nums){
            count[n]++;
        }
        
        
        for(auto n:nums){
            
            //cannot be included in seq
            if(count[n]==0) continue;
            
            
            //if number is required as next in seq
            if(req[n]>0){
                count[n]--;
                req[n]--;
                
                
                req[n+1]++;
            }
            //else create a new sequence using this number
            else if(count[n]>0 && count[n+1]>0 && count[n+2]>0){
                
                count[n]--;
                count[n+1]--;
                count[n+2]--;
                
                req[n+3]++;
            }
            else return false;
            
        }
        
        return true;
        
    }
};