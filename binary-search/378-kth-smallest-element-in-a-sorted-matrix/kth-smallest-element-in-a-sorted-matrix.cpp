class Solution {
public:
    int lessThan(vector<vector<int>>& matrix, int n, int m, int mid) {
        int row = n-1,col = 0, cnt = 0;

        while(row >= 0 && col < m) {
            if(matrix[row][col] <= mid) {
                cnt = cnt + row + 1;
                col++;
            }
            else row--;
        }
        return cnt;       
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        int res = -1;
        int low = matrix[0][0], high = matrix[n-1][m-1];

        while(low<=high) {
            int mid = low + (high-low)/2;
            int ans = lessThan(matrix,n,m,mid);
            if(ans<k) low = mid+1;
            else {
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
};