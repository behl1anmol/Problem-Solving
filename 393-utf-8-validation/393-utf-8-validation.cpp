class Solution {
public:
    bool validUtf8(vector<int>& data) {
        
        int c = 0;
        
        for(auto i : data){
            
            if(c==0){
                if((i>>5) == 0b110) c = 1;
                else if((i>>4) == 0b1110) c = 2;
                else if((i>>3) == 0b11110) c = 3;
                else if((i>>7) == 1) return false;
            }
            else{
                if((i >> 6) != 2) return false;
                c--;
            }
        }
        return c==0;
        
        
    }
};