class Solution {
public:
    
    bool isPalindrome(string& s){
        
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++; right--;
        }
        
        return true;
        
    }
    
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        vector<vector<int>> ans;
        
        int n = words.size();
        
        unordered_map<string,int> mp;
        
        for(int i=0;i<n;i++){
            string temp = words[i];
            reverse(temp.begin(), temp.end());
            mp[temp] = i;
        }

        //for handeling empty string
        
        if(mp.find("")!=mp.end()){
            
            for(int i=0;i<n;i++){
                
                if(mp[""] == i) continue;
                
                if(isPalindrome(words[i]))
                    ans.push_back({i,mp[""]});
            }
        }
        
        
        for(int i=0;i<n;i++){
            
            string word = words[i];
            string left = "";
            string right = word;
            int wsz = word.size();
            
            for(int j=0;j<wsz;j++){
                
                left.push_back(words[i][j]);
                right.erase(0,1);
                
                if((mp.find(left)!=mp.end()) && mp[left]!=i && isPalindrome(right))
                    ans.push_back({i, mp[left]});
                    
                if((mp.find(right)!=mp.end()) && mp[right]!=i && isPalindrome(left))
                    ans.push_back({mp[right],i});
          
            }  
            
        }
        
        
        return ans;
        
        
        
    }
};