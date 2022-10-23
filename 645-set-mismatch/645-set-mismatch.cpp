class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        
        map<int,int>mp;
        
        set<int>st;
        
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            st.insert(nums[i]);
        }
        
        int m = 1;
        for(auto i:st){
            if(i != m)break;
            m++;
        }
        
        //cout<<m<<endl<<n-1;
        vector<int>ans(2);
        
        ans[1] = m;
        int ele = nums[0];
        int idx = 0;
        
        for(int i=0;i<n;i++){
            if(mp[nums[i]]>1){
                ans[0] = nums[i];
                idx = i;
                break;
            }
        }
        
        return ans;
    }
};