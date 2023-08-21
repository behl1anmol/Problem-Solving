class Solution {
public:
    
    bool _canReach(vector<int> &arr, vector<int> &visited ,int i){
        
        if(i >= arr.size() || i < 0) return false;
        if(visited[i]==1) return false;
        if(arr[i] == 0) return true;

        visited[i] = 1;
        return _canReach(arr, visited, i-arr[i]) | _canReach(arr,visited, i+arr[i]);
    }
    bool canReach(vector<int>& arr, int start) {

        vector<int> visited(arr.size(),0);
        return _canReach(arr, visited, start);
    }
};