class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        bool ans = false;
        int unequalCount = 0;
        vector<int> idxs;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                idxs.push_back(i);
                unequalCount++;
            }
        }
        
        if(unequalCount > 2 || unequalCount == 1) ans = false;
        else if(unequalCount == 0) ans = true;
        else{
            if(s1[idxs[0]]==s2[idxs[1]] && s1[idxs[1]]==s2[idxs[0]])
                ans = true;
        }
        return ans;
    }
};