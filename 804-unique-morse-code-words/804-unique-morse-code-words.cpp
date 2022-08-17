class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        string code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        
        set<string>morse;
        int n = words.size();
        
        for(int i=0;i<n;i++){
            string s = "";
            for(int j=0;j<words[i].size();j++){
                
                s = s + code[words[i][j]-'a'];
                
            }
            morse.insert(s);
        }
        return morse.size();
        
        
    }
};