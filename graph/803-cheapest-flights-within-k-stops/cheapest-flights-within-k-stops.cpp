class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<int> a(n,1e8);
        a[src] = 0;
        for(int i=0;i<=k;i++) {
            vector<int> t = a;
            for(int j=0;j<edges.size();j++) {
                int s = edges[j][0];
                int d = edges[j][1];
                int wt = edges[j][2];
                if(a[s] != 1e8 && t[d] > a[s] + wt) t[d] = a[s] + wt;
            }
            a = t;
        }
        if(a[dst] == 1e8) return -1;
        return a[dst]; 
    }
};