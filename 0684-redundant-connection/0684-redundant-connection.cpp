class Solution {
public:
    map<int, vector<int>> createGraph(vector<vector<int>> edges)
    {
        map<int, vector<int>> graph;
        for (auto edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }
    map<int,int> CreateIndegreeMap(vector<vector<int>> edges)
    {
        map<int,int> indegree;
        for(auto edge:edges){
            indegree[edge[1]]++;
            indegree[edge[0]]++;
        }
        return indegree;
    }
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<int> res;
        queue<int> q;
        map<int, vector<int>> graph = createGraph(edges);
        map<int,int> inDegree = CreateIndegreeMap(edges);
        int nodes = graph.size();
        
        for (auto i = inDegree.begin(); i != inDegree.end(); i++){
            if(i->second == 1){
                q.push(i->first);
            }
        }

        while(!q.empty()){
            auto f = q.front();
            q.pop();
            inDegree[f]--;

            auto adj = graph[f];
            for(auto i:adj){
                if(--inDegree[i] == 1) q.push(i);
            }
        }

        for (int i = edges.size()-1; i >= 0; i--){
            if(inDegree[edges[i][1]] > 0 && inDegree[edges[i][0]] > 0){
                res.push_back(edges[i][0]);
                res.push_back(edges[i][1]);
                break;
            }
        }

        return res;
    }

};