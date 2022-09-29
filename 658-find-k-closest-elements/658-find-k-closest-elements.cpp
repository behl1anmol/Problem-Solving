class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
     
        int n = arr.size();
        vector<pair<int,int>> close;
        vector<int> ans;
        
        
        for(int i=0;i<n;i++){
            close.push_back({abs(x-arr[i]),arr[i]});
        }
        
        sort(close.begin(),close.end());
        
        for(int i=0;i<k;i++){
            ans.push_back(close[i].second);
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};