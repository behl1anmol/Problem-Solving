class Solution {
public:
    
    void transpose(vector<vector<int>>& arr, int n){
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(arr[i][j],arr[j][i]);
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        transpose(matrix, n);
    
        
        for(int i=0; i<n; i++){
            /*for(int j=0,k=n-1; j!=k; j++,k--){
                swap(matrix[i][j], matrix[i][k]);
            }*/
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};