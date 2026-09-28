class Solution {
public:
    bool res = true;
    void dfs(vector<vector<int>>& a, int n, int c, vector<int>& color) {
        color[n] = c;
        for(auto i:a[n]) {
            int neigh = i;
            if(color[neigh] != -1 && color[neigh] == c) res = false;
            if(color[neigh] == -1) dfs(a,neigh,1-c,color);
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++) {
            if(color[i] == -1) dfs(graph,i,0,color);
        }
        return res;
    }
};