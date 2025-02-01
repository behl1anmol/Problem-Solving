/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
        {
            return node;
        }
        map<Node *, int> visited;
        queue<Node *> q;
        map<Node *, Node *> mp;
        Node *cloneGraph = new Node(node->val);
        q.push(node);
        mp[node] = cloneGraph;

        while (!q.empty())
        {
            auto f = q.front();
            q.pop();
            Node *orig = f;
            Node *cpy;
            if (mp.find(orig) == mp.end())
            {
                mp[orig] = new Node(orig->val);
            }
            cpy = mp[orig];
            vector<Node *> nbrs;
            visited[orig] = 1;

            for (auto i : orig->neighbors)
            {
                Node *n;
                if (visited.find(i) == visited.end()) q.push(i);
                if(mp.find(i) == mp.end()) mp[i] = new Node(i->val);
                n = mp[i];
                nbrs.push_back(n);
            }
            cpy->neighbors = nbrs;
        }
        return cloneGraph;
    }
};