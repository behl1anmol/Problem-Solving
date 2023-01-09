class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        
        for(auto ch:word1) mp1[ch]++;
        
        for(auto ch: word2) mp2[ch]++;
        
        for(int i=0;i<26;i++){
            char ch1 = 'a' + i; 
            for(int j=0;j<26;j++){
                char ch2 = 'a' + j;
                if(mp1.count(ch1) && mp2.count(ch2)){
                    if(--mp1[ch1]==0) mp1.erase(ch1);
                    if(--mp2[ch2]==0) mp2.erase(ch2);
                
                    mp1[ch2]++;
                    mp2[ch1]++;
                
                    if(mp1.size()==mp2.size()) return true;
                
                    if(--mp1[ch2] == 0) mp1.erase(ch2);
                    if(--mp2[ch1] == 0) mp2.erase(ch1);
                
                    mp1[ch1]++;
                    mp2[ch2]++;
                }
            }
        }
        return false;
    }
};