class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool isValid(int row, int col, int n, int m) {
        if(row<0 || row>=n || col<0 || col>=m) return false;
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int fresh = 0, time = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                    grid[i][j] = -2;
                }
                else if(grid[i][j] == 1) fresh++;
            }
        }
        while(!q.empty() && fresh>0) {
            time++;
            int s = q.size();
            while(s--) {
                pair<int,int> p = q.front();
                q.pop();
                int r = p.first;
                int c = p.second;
                for(int k=0;k<4;k++) {
                    int row = r + x[k];
                    int col = c + y[k];
                    if(isValid(row,col,n,m) && grid[row][col] == 1) {
                        q.push({row,col});
                        grid[row][col] = -2;
                        fresh--;
                    }
                }
            } 
        }
        if(fresh>0) return -1;
        return time;
    }
};