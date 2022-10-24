class Solution {
public:
    
    bool unique(string curr){
        
        vector<int> arr(26,0);
        
        for(int i=0;i<curr.size();i++){
            arr[curr[i] - 'a']++;
            
            if(arr[curr[i] - 'a']>1) return false;
        }
        return true;
    }
    
    void solution(vector<string> arr, int i, int n, int& ans, string curr){
        if(!unique(curr)) return;
        
        if(i == n){
            ans = max(ans,(int)curr.size());
            return;
        }
        
        solution(arr, i+1, n, ans, curr + arr[i]);
        
        solution(arr, i+1, n, ans, curr);
        
        
    }
    int maxLength(vector<string>& arr) {
        int ans = 0;
        solution(arr, 0, arr.size(), ans, "");
        
        return ans;
    }
};