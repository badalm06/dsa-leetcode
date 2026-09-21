class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool isValid(int i, int j, int n, int m) {
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

    void dfs(vector<vector<int>>& image, int n, int m, int sr, int sc, int color, int oldColor, vector<vector<bool>>& seen) {
        seen[sr][sc] = 1;
        image[sr][sc] = color;
        for(int k=0;k<4;k++) {
            int row = sr + x[k];
            int col = sc + y[k];
            if(isValid(row,col,n,m) && seen[row][col] == 0 && 
            image[row][col] == oldColor) {
                dfs(image,n,m,row,col,color,oldColor,seen);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];
        vector<vector<bool>> seen(n);
        for(int i=0;i<n;i++) {
            vector<bool> t(m,0);
            seen[i] = t;
        }
        dfs(image,n,m,sr,sc,color,oldColor,seen);
        return image;
    }
};