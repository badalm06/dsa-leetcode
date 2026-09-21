#define ll long long
class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& seen, ll& cnt) {
        seen[node] = true;
        cnt++;
        for(auto i:adj[node]) {
            if(!seen[i]) {
                dfs(i, adj, seen, cnt);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i == j) continue;
                
                ll dx = bombs[i][0] - bombs[j][0];
                ll dy = bombs[i][1] - bombs[j][1];

                ll dist = dx*dx + dy*dy;
                ll r = bombs[i][2];
                if(dist <= r*r) {
                    adj[i].push_back(j);
                }
            }
        }
        ll maxi=0;
        for(int i=0;i<n;i++) {
            vector<bool> seen(n);
            ll c=0;
            dfs(i,adj,seen,c);
            maxi=max(maxi,c);
        }
        return maxi;
    }
};