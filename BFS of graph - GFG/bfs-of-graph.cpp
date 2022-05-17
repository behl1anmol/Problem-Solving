// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    
    void bfsUtil(vector<int>adj[], vector<int> &vis, vector<int> &ans,int i){
        
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        ans.push_back(i);
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            
            for(auto it : adj[front]){
                if(vis[it]==0){
                    q.push(it);
                    vis[it] = 1;
                    ans.push_back(it);
                }
            }
            
        }
    }
    
    
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        vector<int> ans;
        
        bfsUtil(adj,vis,ans,0);
        
        /*for(int i=0;i<V;i++){
            if(vis[i]==0){
                bfsUtil(adj,vis,ans,i);
            }
        }*/
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends