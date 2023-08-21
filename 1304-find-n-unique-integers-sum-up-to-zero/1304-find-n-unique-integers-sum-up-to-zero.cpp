class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int> result;
        if(n%2!=0){
            result.push_back(0);
            n--;
        }
        int i = 1;
        while(n!=0){
            result.push_back(i);
            result.push_back((-1)*i);
            n = n-2;
            i++;
        }
        
        return result;
    }
};