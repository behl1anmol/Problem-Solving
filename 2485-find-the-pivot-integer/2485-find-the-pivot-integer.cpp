class Solution {
public:

    //another good approach is to use simple maths.
    //mathematically it can be proven that sum of all integers upto n is pivot*pivot

    int pivotInteger(int n){
        int sum = n*(n+1)/2;
        int pivot= sqrt(sum);

        return pivot * pivot == sum ? pivot : -1; 
    }

    int _pivotInteger(int n) {
        int leftSum[n+1], rightSum[n+1];
        int sumTillNow = 0;

        for(int i = 1; i <= n; i++){
            sumTillNow += i;
            leftSum[i] = sumTillNow;
        }

        sumTillNow = 0;
        for(int i = n; i >=1 ; i--){
            sumTillNow += i;
            rightSum[i] = sumTillNow;
        }

        for(int i=1 ; i <= n; i++){
            if(leftSum[i] == rightSum[i]){
                return i;
            }
        }

        return -1;
        
    }
};