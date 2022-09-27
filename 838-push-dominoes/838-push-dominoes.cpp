class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n = dominoes.size();
        string prev = "";
        string curr = dominoes;
        
        while(dominoes!=prev){
            
            for(int i=0;i<n;i++){
                
                if(dominoes[i]=='R'){
                    if(i<n-2 && dominoes[i+2]=='L'){
                        continue;
                    }
                    else if(i<n-1 && dominoes[i+1]!='L')curr[i+1] = 'R';
                }
                 if(dominoes[i]=='L'){
                    if(i>2 && dominoes[i-2]=='R'){
                        continue;
                    }
                    else if(i>0 && dominoes[i-1]!='R') curr[i-1] = 'L';
                }
            }
            prev = dominoes;
            dominoes = curr;
            
        }
        
        return dominoes;
    }
};