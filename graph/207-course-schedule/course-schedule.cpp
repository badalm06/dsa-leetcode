class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<vector<int>> a(n);
        vector<int> indegree(n,0);
        vector<int> res;
        for(int i=0;i<edges.size();i++) {
            int src = edges[i][0];
            int dest = edges[i][1];
            a[src].push_back(dest);
            indegree[dest]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(int i=0;i<a[node].size();i++) {
                int n = a[node][i];
                indegree[n]--;
                if(indegree[n] == 0) q.push(n);
            }
        }
        if(res.size() == n) return true;
        return false;
    }
};