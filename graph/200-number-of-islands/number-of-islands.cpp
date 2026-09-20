class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool isValid(int i, int j, int n, int m) {
        // This tell, the row/col u want to visit is in the matrix or not
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

    void dfs(vector<vector<char>>& grid, int n, int m, int i, int j, 
            vector<vector<bool>>& seen) {
                seen[i][j] = 1;
                for(int k=0;k<4;k++) {
                    int row = i + x[k];
                    int col = j + y[k];
                    if(isValid(row,col,n,m) && seen[row][col] == false
                        && grid[row][col] == '1') {
                        dfs(grid,n,m,row,col,seen);
                    }
                }
                return;
            }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        int i,j;

        // This is how, u make a 2-D array with all element 0
        vector<vector<bool>> seen(n);
        for(int i=0;i<n;i++) {
            vector<bool> t(m,0);
            seen[i] = t;
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == '1' && seen[i][j] == false) {
                    dfs(grid,n,m,i,j,seen);
                    res++;
                }
            }
        }
        return res;
    }
};