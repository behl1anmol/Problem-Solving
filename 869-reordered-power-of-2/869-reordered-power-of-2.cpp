class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        string s =to_string(n);
        sort(s.begin(),s.end());
        
        vector<string> arr;
        
        for(int i=0;i<30;i++){
            int j = 1<<i;
            string k = to_string(j);
            sort(k.begin(), k.end());
            if(k==s) return true;
        }
        return false;
        
        
        
    }
};