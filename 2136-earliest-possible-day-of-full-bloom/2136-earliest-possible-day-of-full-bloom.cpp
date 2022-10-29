class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int,int>> arr;
        
        for(int i=0;i<plantTime.size();i++){
            arr.emplace_back(growTime[i], plantTime[i]);
        }
        
        sort(arr.rbegin(), arr.rend());
        int currTime = 0;
        int maxBloom = 0;
        
        for(auto [grow,plant] : arr){
            currTime += plant;
            int currBloom = currTime + grow;
            maxBloom = max(maxBloom, currBloom);
        }
        
        return maxBloom;
        
    }
};