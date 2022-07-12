class Solution {
public:
    
    static bool compare(vector<int>a, vector<int>b){
        return (a[0] < b[0]);
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            vector<int> temp;
            
            if(start==-1 && end==-1) continue;
            
            for(int k=i+1; k<n; k++){
                if(intervals[k][0] <= end){
                    start = min(start, intervals[k][0]);
                    end = max(end, intervals[k][1]);
                    intervals[k][0] = -1;
                    intervals[k][1] = -1;
                }
            }
            temp.push_back(start);
            temp.push_back(end);
            ans.push_back(temp);
            
        }
        return ans;
    }
};