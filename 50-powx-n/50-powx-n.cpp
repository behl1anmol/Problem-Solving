class Solution {
public:
    
    double binaryExponentiation(double a, long long int n){
        double res=1;

        while(n>0){
            if(n&1){
                res=res*a;
            }
            a=a*a;
            n>>=1;
        }
        return res;   
}
    
    
    double myPow(double x, int n) {
        if(n<0) return (1/binaryExponentiation(x, abs(n)));
        return binaryExponentiation(x,n);
    }
};