class Solution {
public:
    string intToRoman(int num) {
        unordered_map <int,string> roman;
        
        roman[1] = "I";
        roman[5] = "V";
        roman[10] = "X";
        roman[50] = "L";
        roman[100] = "C";
        roman[500] = "D";
        roman[1000] = "M";
        
        int div = 1;
        
        while(num>=div) div *= 10;
        
        div /= 10;
        string res = "";
        
        while(num){
            int leftNum = num/div;
            
            if(leftNum <= 3){
                for(int i=0;i<leftNum;i++)
                    res += roman[div];
            }
            
            if(leftNum == 4) res += roman[div] + roman[div*5];
            
            if(leftNum >= 5 && leftNum <= 8){
                res += roman[div * 5];
                
                for(int i=0;i<(leftNum-5);i++)
                    res += roman[div];
            }
            
            if(leftNum >=9) res += roman[div] + roman[div*10];
            
            num = floor(num % div);
            div = div/10;
            
        }
        return res;
    }
};