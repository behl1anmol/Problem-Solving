class Solution {
public:
    
    double binaryExponentiation(double a, long long int n){
    if(n==0)
        return 1;

    double res = binaryExponentiation(a,n/2);

    if(n%2!=0)
        return res*res*a;
    else
        return res*res;
            
}
    
    
    double myPow(double x, int n) {
        if(n<0) return (1/binaryExponentiation(x, abs(n)));
        return binaryExponentiation(x,n);
    }
};