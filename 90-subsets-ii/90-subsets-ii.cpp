class Solution {
public:
    void subset(vector<int> arr, int n, int i, vector<int>&ans, set<vector<int>>&subsets){

        subsets.insert(ans);
        for(;i<n;i++){
            ans.push_back(arr[i]); 
            subset(arr,n,i+1,ans, subsets);
            ans.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        int n = nums.size();
        subset(nums, n, 0, ans, st);
        
        vector<vector<int>> subsets(st.begin(), st.end());
        
     return subsets;
    }
};