class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool isValid(int i,int j, int n, int m) {
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

    void dfs(vector<vector<int>>& grid, int n, int m, int i, int j,
    vector<vector<bool>>& seen) {
        seen[i][j] = true;
        for(int k=0;k<4;k++) {
            int row = i + x[k];
            int col = j + y[k];
            if(isValid(row,col,n,m) && seen[row][col] == false &&
            grid[row][col] == 1) {
                dfs(grid,n,m,row,col,seen);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        vector<vector<bool>> seen(n);
        for(int i=0;i<n;i++) {
            vector<bool>t(m,0);
            seen[i] = t;
        }

        // for Top and Bottom
        for(int j=0;j<m;j++) {
            if(grid[0][j] == 1 && seen[0][j] == false) {
                dfs(grid,n,m,0,j,seen);
            }
            if(grid[n-1][j] == 1 && seen[n-1][j] == false) {
                dfs(grid,n,m,n-1,j,seen);
            }
        }

        // for Left and Right
        for(int i=0;i<n;i++) {
            if(grid[i][0] == 1 && seen[i][0] == false) {
                dfs(grid,n,m,i,0,seen);
            }
            if(grid[i][m-1] == 1 && seen[i][m-1] == false) {
                dfs(grid,n,m,i,m-1,seen);
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 1 && seen[i][j] == false) {
                    ans++;
                }
            }
        }
        return ans;
    }
};