// Solution using Binary search and bfs
class Solution {
public:
    bool isValid(int i, int j, int n, int m) {
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    bool bfs(vector<vector<int>>&a, int n, int m, int mid) {
        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1};
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n);
        for(int i=0;i<n;i++) {
            vector<int> t(m,0);
            vis[i] = t;
        }
        vis[0][0] = 1;
        q.push({0,0});

        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int row = p.first;
            int col = p.second;
            if(row == n-1 && col == m-1) return true;
            for(int k=0;k<4;k++) {
                int r = row + x[k];
                int c = col + y[k];
                if(isValid(r,c,n,m) && vis[r][c] == 0 && mid >= a[r][c]) {
                    q.push({r,c});
                    vis[r][c] = 1;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int l = grid[0][0];
        int h = grid[0][0];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                h = max(h,grid[i][j]);
            }
        }
        int res = 0;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(bfs(grid,n,m,mid)) {
                res = mid;
                h = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }
};