class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int n = stations.size();
        
        priority_queue<int> pq;
        
        int ans  = 0;        
        int fuel_till_now = startFuel;
        int i = 0;
        while(fuel_till_now < target){
            
            while(i<n && stations[i][0]<=fuel_till_now){
                pq.push(stations[i][1]);
                
                i++;
            }
            
            if(pq.empty()){
                ans = -1;
                break;
            }
            
            fuel_till_now += pq.top();
            pq.pop();
            
            ans++;
        }
        
        return ans;
        
    }
};