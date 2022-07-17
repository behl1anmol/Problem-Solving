class Solution {
public:

    int _uniquePaths(int i, int j, int m, int n, vector<vector<int>> &visited, int ans){
        
        if(i==m-1 && j==n-1){
            visited[i][j] = 1;
            return 1;
        }
        
        int right_path = 0;
        int down_path = 0;
        
        if(j < n-1){
            if(visited[i][j+1] > 0) right_path = visited[i][j+1];
            else right_path = _uniquePaths(i, j+1, m, n, visited, ans);
        }
        if(i < m-1){
            if(visited[i+1][j] > 0) down_path = visited[i+1][j];
            else down_path = _uniquePaths(i+1, j, m, n, visited, ans);
        }
        
        visited[i][j] = right_path + down_path;
        
        ans = ans + right_path + down_path;
        
        return ans;

    }
    
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> visited(m, vector<int> (n, 0));
        
        return _uniquePaths(0, 0, m, n, visited, 0);
        
        
    }
};