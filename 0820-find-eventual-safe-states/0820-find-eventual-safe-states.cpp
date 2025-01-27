class Solution {
public:
    void _eventualSafeNodes(vector<vector<int>>& graph,
                            vector<int>& vis,
                            vector<int>& su,
                            int startNode)
    {
        stack<int> stk;
        stk.push(startNode);

        while (!stk.empty()) {
            int currNode = stk.top();

            vis[currNode] = 1;
            bool allSafe = true;
            for (int neighbour : graph[currNode]) {
            if (vis[neighbour] == 0) {
                stk.push(neighbour);
                allSafe = false;
            } else if (su[neighbour] == 0 || su[neighbour] == -1) {
                allSafe = false;
                while(!stk.empty() && stk.top() != currNode){
                    stk.pop();
                }
                su[currNode] = 0;
                stk.pop();
                break;
            }
        }

            if (allSafe) {
                su[currNode] = 1;
                stk.pop();
            }
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> vis(graph.size(), 0);
        vector<int> su(graph.size(), -1);
        
        int n = graph.size()-1;
        for(int j = n; j >= 0; j--)
        {
            if(vis[j] == 1) continue;
            _eventualSafeNodes(graph, vis, su, j);
        }

        vector<int> ans;
        for(int i=0;i<su.size();i++){
            if(su[i]) ans.push_back(i);
        }

        return ans;
    }
};