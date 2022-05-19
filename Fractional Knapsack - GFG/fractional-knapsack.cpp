// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool compare(Item a, Item b){
        float pw1 = (double)a.value/a.weight;
        float pw2 = (double)b.value/b.weight;
        
        return pw1>pw2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        int M=W;
        double ans = 0.0;
        
        sort(arr,arr+n,compare);
        int i =0;
        
        /*for(int j=0;j<n;j++){
            cout<<arr[j].value<<" ";
        }*/
        //cout<<endl;
        
        for(i=0;i<n;i++){
            if(arr[i].weight<=M){
                ans += arr[i].value;
                M -=arr[i].weight;
            }
            else{
                ans+= ((double)arr[i].value/(double)arr[i].weight)*M;
                break;
            };
        }

        
        return ans;
        
        
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends