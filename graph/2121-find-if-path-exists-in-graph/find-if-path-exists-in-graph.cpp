class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++) {
            int src = edges[i][0];
            int dest = edges[i][1];
            adj[src].push_back(dest);
            adj[dest].push_back(src);
        }
        vector<bool> seen(n,0);
        queue<int> q;
        q.push(source);
        seen[source] = true;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(node == destination) return true;
            for(int i=0;i<adj[node].size();i++) {
                int n = adj[node][i];
                if(seen[n] == false) {
                    q.push(n);
                    seen[n] = true;
                }
            }
        }
        return false;
    }
};