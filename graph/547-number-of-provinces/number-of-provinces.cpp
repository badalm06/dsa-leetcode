class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int n, int node,           vector<bool>& seen) {
        seen[node] = true;
        for(int i=0;i<n;i++) {
            if(isConnected[node][i] == 1 && seen[i] == false) {
                dfs(isConnected, n, i, seen);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> seen(n);
        int res = 0;
        
        for(int i=0;i<n;i++) {
            if(seen[i] == false) {
                dfs(isConnected,n,i,seen);
                res++;
            }
        }
        return res;
    }
};