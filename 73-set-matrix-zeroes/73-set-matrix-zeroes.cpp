class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        int i,j,col=1;
        
        for(i = 0; i < m; i++){
            if(matrix[i][0]==0)col=0;
            for(j=1; j<n; j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(i = 1; i<m; i++){
            for(j=1; j<n; j++){
                if(matrix[i][0]==0 || matrix[0][j]==0) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(matrix[0][0]==0)
            for(i=0;i<n;i++) matrix[0][i] = 0;
        if(col == 0)
            for(j=0;j<m;j++) matrix[j][0] = 0;
             
        
    }
};