/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new List<Node>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new List<Node>();
    }

    public Node(int _val, List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

public class Solution {
    public Node CloneGraph(Node node) {
        if (node == null) return null;

        Dictionary<Node, int> visited = new Dictionary<Node, int>(); // Track visited nodes
        Queue<Node> q = new Queue<Node>(); // BFS queue
        Dictionary<Node, Node> mp = new Dictionary<Node, Node>(); // Mapping original nodes to cloned nodes

        Node cloneGraph = new Node(node.val); // Create first clone
        q.Enqueue(node);
        mp[node] = cloneGraph;

        while (q.Count > 0) {
            Node orig = q.Dequeue();
            Node cpy;

            if (!mp.ContainsKey(orig))
                mp[orig] = new Node(orig.val);
            
            cpy = mp[orig];
            List<Node> nbrs = new List<Node>();
            visited[orig] = 1;

            foreach (var i in orig.neighbors) {
                Node n;
                if (!visited.ContainsKey(i)) q.Enqueue(i);
                if (!mp.ContainsKey(i)) mp[i] = new Node(i.val);
                n = mp[i];
                nbrs.Add(n);
            }
            
            cpy.neighbors = nbrs;
        }
        return cloneGraph;
    }
}
