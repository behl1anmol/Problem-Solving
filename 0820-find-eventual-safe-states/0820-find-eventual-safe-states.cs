public class Solution {
    public void _EventualSafeNodes(int[][] graph, 
                                   ref List<int> vis,
                                   ref List<int> su,
                                   int startNode){
        Stack<int> stk = new Stack<int>();
        stk.Push(startNode);

        while(stk.Count() > 0){
            int currNode = stk.Peek();

            vis[currNode] = 1;
            bool allSafe = true;

            foreach(var neighbour in graph[currNode]){
                
                if(vis[neighbour] == 0){
                    stk.Push(neighbour);
                    allSafe = false;
                } else if(su[neighbour] == 0 || su[neighbour] == -1){
                    allSafe = false;
                    while(stk.Count() > 0 && stk.Peek() != currNode){
                        stk.Pop();
                    }
                    su[currNode] = 0;
                    stk.Pop();
                    break;
                }
            }
            
            if(allSafe){
                su[currNode] = 1;
                stk.Pop();
            }
        }

    }
    public IList<int> EventualSafeNodes(int[][] graph) {
        List<int> vis = new List<int>();
        vis = Enumerable.Repeat(0, graph.Length).ToList();
        List<int> su = new List<int>();
        su = Enumerable.Repeat(-1, graph.Length).ToList();

        int n = graph.Length-1;

        for(int j = n; j >= 0; j--)
        {
            if(vis[j] == 1) continue;
            _EventualSafeNodes(graph, ref vis, ref su, j);
        }

        List<int> ans = new List<int>();
        for(int i=0;i<su.Count();i++){
            if(su[i] == 1) ans.Add(i);
        }

        return ans;
    }
}