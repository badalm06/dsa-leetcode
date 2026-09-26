class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> a(n);
        vector<int> indegree(n,0);
        for(int i=0;i<edges.size();i++) {
            int src = edges[i][0];
            int dest = edges[i][1];
            a[src].push_back(dest);
            a[dest].push_back(src);
            indegree[src]++;
            indegree[dest]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) {
            if(indegree[i] == 1) q.push(i);
        }

        int rem = n;
        while(rem > 2) {
            int s = q.size();
            rem -= s;
            while(s--) {
                int node = q.front();
                q.pop();
                for(int i=0;i<a[node].size();i++) {
                    int neigh = a[node][i];
                    indegree[neigh]--;
                    if(indegree[neigh] == 1) q.push(neigh);
                }
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};