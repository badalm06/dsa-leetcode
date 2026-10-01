// Using Dijkstra Algorithm
class Solution {
public:
    bool valid(int r, int c, int n, int m) {
        if(r<0 || r>=n || c<0 || c>=m) return false;
        return true;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n);
        for(int i=0;i<n;i++) {
            vector<int> t(m,INT_MAX);
            res[i] = t;
        }

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        res[0][0] = grid[0][0];
        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1};

        while(!pq.empty()) {
            pair<int,pair<int,int>> p = pq.top();
            pq.pop();
            int dis = p.first;
            int row = p.second.first;
            int col = p.second.second;
            if(dis > res[row][col]) continue;
            for(int k=0;k<4;k++) {
                int r = row + x[k];
                int c = col + y[k];
                if(!valid(r,c,n,m)) continue;
                int newWt = max(dis, grid[r][c]);
                if(newWt < res[r][c]) {
                    res[r][c] = newWt;
                    pq.push({newWt, {r,c}});
                }
            }
        }
        return res[n-1][m-1];
    }
};