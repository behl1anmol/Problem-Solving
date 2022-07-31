//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    void Insert_rev(stack<int> &St, int num){
        
        if(St.empty()) St.push(num);
        else{
            
            int x = St.top();
            St.pop();
            Insert_rev(St, num);
            St.push(x);
            
            
        }
        
    }


    void Reverse_utils(stack<int> &St){
        
        if(St.empty()) return;
        
        int num = St.top();
        St.pop();
        Reverse_utils(St);
        
        Insert_rev(St,num);
    }

    
    vector<int> Reverse(stack<int> St){
        Reverse_utils(St);
        vector<int> ans;
        
        while(!St.empty()){
            ans.insert(ans.begin(),St.top());
            St.pop();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        vector<int> ans=ob.Reverse(St);
        for(int i=0;i<N;i++){
            cout<<ans[i];
            if(i!=N-1) cout<<" ";
        }
        cout<<endl;
    }
}
// } Driver Code Ends