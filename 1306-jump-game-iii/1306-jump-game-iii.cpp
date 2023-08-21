class Solution {
public:
    
bool canReach(vector<int>& arr, int start) {

        vector<int> vis(arr.size(),0);
        
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            if(arr[front]==0) return true;
            vis[front] = 1;
            int left = front - arr[front];
            int right = front + arr[front];

            if((left >=0 && left < arr.size()) && vis[left] == 0){
                q.push(left);
            }
            
            if((right>=0 && right < arr.size()) && vis[right] == 0 ){
                q.push(right);
            }
        }
        
        return false;        
    }
};