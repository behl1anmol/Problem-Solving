class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int> freq;
        
        for(auto i:magazine){
            freq[i]++;
        }
        
        for(auto i:ransomNote){
            if(!freq[i]) return false;
            freq[i]--;
        }
        return true;
        
        
    }
};