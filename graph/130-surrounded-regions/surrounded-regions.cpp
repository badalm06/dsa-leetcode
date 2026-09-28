class Solution {
public:
    int x[4] = {1,-1,0,0};
    int y[4] = {0,0,-1,1};
    bool isValid(int i, int j, int n, int m) {
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

    void dfs(vector<vector<char>>& b, int n, int m, int i, int j) {
        b[i][j] = '#';
        for(int k=0;k<4;k++) {
            int r = i + x[k];
            int c = j + y[k];
            if(isValid(r,c,n,m) && b[r][c] == 'O') dfs(b,n,m,r,c);
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        
        // first row
        for(int j=0;j<m;j++) {
            if(board[0][j] == 'O') dfs(board,n,m,0,j);  
        }
        // last row
        for(int j=0;j<m;j++) {
            if(board[n-1][j] == 'O') dfs(board,n,m,n-1,j);
        }
        // first col
        for(int i=0;i<n;i++) {
            if(board[i][0] == 'O') dfs(board,n,m,i,0);
        }
        //last col
        for(int i=0;i<n;i++) {
            if(board[i][m-1] == 'O') dfs(board,n,m,i,m-1);
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
        return;
    }
};