class Solution {
public:
        void _eventualSafeNodes(vector<vector<int>>& graph,
                                vector<int>& vis,
                                vector<int>& su,
                                int startNode)
        {
            // Explanation: The stack tracks the current exploration path.
            stack<int> stk;
            stk.push(startNode);

            while (!stk.empty()) {
                int currNode = stk.top();

                vis[currNode] = 1;
                bool allSafe = true;  // Explanation: We assume all neighbors are safe until proven otherwise.
                for (int neighbour : graph[currNode]) {
                    // Explanation: If the neighbor is unvisited, we explore it.
                    if (vis[neighbour] == 0) {
                        stk.push(neighbour);
                        allSafe = false;
                    } else if (su[neighbour] == 0 || su[neighbour] == -1) { // Explanation: If the neighbor visited and is unsafe or unmarked, we mark the current node as unsafe.
                        allSafe = false;
                        // Explanation: We pop the stack until we reach the neighbor to mark the path as unsafe.
                        while(!stk.empty() && stk.top() != currNode){
                            stk.pop();
                        }
                        // Explanation: We mark the neighbor as unsafe.
                        su[currNode] = 0;
                        stk.pop();
                        break;
                    }
                }

                // Explanation: If, after checking all neighbors, none are unsafe, we mark the current node as safe.
                if (allSafe) {
                    su[currNode] = 1;
                    stk.pop();
                }
            }
        }

        // Explanation: We iterate in reverse so previously visited nodes have known statuses (safe/unsafe).
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            vector<int> vis(graph.size(), 0);
            vector<int> su(graph.size(), -1);
            
            int n = graph.size()-1;
            // Explanation: We iterate in reverse so previously visited nodes have known statuses (safe/unsafe).
            for(int j = n; j >= 0; j--)
            {
                // Explanation: If the node is already visited, we skip it.
                if(vis[j] == 1) continue;
                _eventualSafeNodes(graph, vis, su, j);
            }

            // Explanation: Gather all nodes marked safe.
            vector<int> ans;
            for(int i=0;i<su.size();i++){
                if(su[i]) ans.push_back(i);
            }

            return ans;
        }
};