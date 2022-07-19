class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
        
        set<int> st;
        
        for(int num:nums){
            st.insert(num);
        }
        
        int ans = 0;
        
        for(int num:nums){
            int subseqCount = 0;
            if(st.count(num-1)==0){
                
                int curr = num;
                subseqCount++;
                
                while(st.count(curr+1)){
                    curr++;
                    subseqCount++;
                }
            }
            ans = max(ans, subseqCount);
        }
        return ans; 
    }
};