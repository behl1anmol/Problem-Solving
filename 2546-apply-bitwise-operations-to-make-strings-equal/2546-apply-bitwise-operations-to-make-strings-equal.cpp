class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        return (count(s.begin(),s.end(),'1')>0) == (count(target.begin(),target.end(),'1')>0);
    }
};