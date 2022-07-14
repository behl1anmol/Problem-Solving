class Solution {
public:
    
    bool binarySearch(vector<vector<int>>& matrix, int i, int left, int right, int target){
        
        do{
            int mid = (left+right)/2;
            if(target == matrix[i][mid]) return true;
            
            if(target <= matrix[i][mid]) right = mid-1;
            
            if(target > matrix[i][mid]) left = mid+1;
            
        }while(left<=right);
        
        return false;
        
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i=0;i<n;i++){
                if(target >= matrix[i][0] && target <= matrix[i][m-1])
                    return binarySearch(matrix, i, 0, m, target);
        }
        
        return false;
    }
};