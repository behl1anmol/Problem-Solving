//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

void subset(int &s,vector<int> arr, int n, int i, vector<int>&ans, vector<int>&sum){

    for(;i<n;i++){
        ans.push_back(arr[i]);
        s+=arr[i];
        sum.push_back(s);
        subset(s, arr,n,i+1,ans, sum);
        s-=arr[i];
        ans.pop_back();
    }


}


    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here

        vector<int>ans;
        vector<int>sum;
        sum.push_back(0);
        int s = 0;
        subset(s, arr, N, 0, ans, sum);

        return sum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends