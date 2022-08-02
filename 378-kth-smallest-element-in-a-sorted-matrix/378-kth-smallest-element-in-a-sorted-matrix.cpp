class Solution {
public:
    
    int count_smaller_than_mid(vector<vector<int>> &matrix, int mid){
        int cnt = 0;
        
        for(int i=0;i<matrix.size();i++){
            cnt += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        return cnt;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        //Approach 2 Binary Search
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        
        while(left<=right){
            int mid = left + (right-left)/2;
            
            if(count_smaller_than_mid(matrix,mid) < k) left = mid+1;
            else right = mid-1;
        }
        
        return left;
        
    
        /*
        Approach 1 
        vector<int> arr;
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                arr.push_back(matrix[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        

        return arr[k-1];*/
        
    }
};