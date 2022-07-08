#include <bits/stdc++.h> 
#define sumN(N) N*(N+1)/2
#define sumSquareN(N) N*(N+1)*(2*N+1)/6
#define ll long long int

ll sumArr(vector<int> arr, int n){
    ll sum = 0;
    for(int i=0;i<n;i++) sum+=arr[i];
    return sum;
}

ll squareSumArr(vector<int> arr, int n){
    ll squareSum = 0;
    for(int i=0;i<n;i++) squareSum+=(arr[i]*arr[i]);
    return squareSum;
}

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    ll len = arr.size();
    //actual sum upto n 
    ll s = sumN(len);
    ll s2 = sumSquareN(len);
    
    //sum w.r.t array
    ll _s = sumArr(arr,len);
    ll _s2 = squareSumArr(arr,len);
    
    ll sumDiff = s-_s;
    ll squareSumDiff = s2-_s2;

    
    //solving linear equation in 2 variables 
    ll missingNumber = ((squareSumDiff/sumDiff)+sumDiff)/2;
    ll repeatedNumber = squareSumDiff/sumDiff-missingNumber;
    return {missingNumber, repeatedNumber};
}
