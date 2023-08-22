//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > minHeap;
        
        vector<int> node;
        node.push_back(0);
        node.push_back(0);
        
        minHeap.push(node);
        
        vector<int> vis(V,0), par(V,-1), wt(V,INT_MAX);
        wt[0] = 0;
        vis[0] = 1;
        while(!minHeap.empty()){
            node = minHeap.top();
            minHeap.pop();
            int vw = node[0];
            int v = node[1];
            vis[v] = 1;
            for(auto it : adj[v]){
                int u = it[0];
                int uw = it[1];
                
                if(vis[u]==0 && wt[u] > uw){
                    //cout<<u<<" "<<uw<<" "<<vis[u]<<endl;
                    wt[u] = uw;
                    par[u] = v;
                    minHeap.push({wt[u], u});
                }
            }
        }
        //cout<<endl;
    //for(int i=0;i<V;i++){
      //  cout<<i<<" "<<par[i]<<" "<<wt[i]<<endl;
    //}
        return accumulate(wt.begin(), wt.end(), 0);
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends