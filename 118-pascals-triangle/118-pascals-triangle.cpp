class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       if(numRows==1){ return {{1}}; }
        if(numRows==2){ return {{1},{1,1}}; }
       vector<vector<int>> ans{{1},{1,1}};
        int i,j;
        for(i=0;i<numRows-2;i++){
            
            vector<int>arr;
            int n = ans.size();
            int m = ans[n-1].size();
            vector<int> temp(ans[n-1]);
            int sum = ans[n-1][0];    
            
            arr.push_back(1);
            for(j=0;j<m-1;j++){
                sum = sum + temp[j+1];
                arr.push_back(sum);
                sum = sum-temp[j];
            }
            arr.push_back(1);
            ans.push_back(arr);
            
        }
            
        return ans;
    }
};