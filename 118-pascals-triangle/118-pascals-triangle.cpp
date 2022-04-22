class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       if(numRows==1){ return {{1}}; }
        if(numRows==2){ return {{1},{1,1}}; }
       vector<vector<int>> ans{{1}};
        int i,j;
        for(i=1;i<numRows;i++){
            vector<int> temp;
            int sum;
            temp.push_back(1);
            
            for(j=1;j<i;j++){
                sum = ans[i-1][j] + ans[i-1][j-1];
                temp.push_back(sum);
            }
            temp.push_back(1);
            ans.push_back(temp);
            
        }
            
        return ans;
    }
};