class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char, int> mp;
        
        for(auto ch:s){
            mp[ch]++;
        }
        
        int val = mp.begin()->second;
        for(auto it : mp){
            if(val != it.second) return false;
        }
        return true;
    }
};