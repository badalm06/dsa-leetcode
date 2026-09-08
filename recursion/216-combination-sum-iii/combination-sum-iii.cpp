class Solution {
public:
    void solve(int idx, int k, int n, vector<int>& temp,
               vector<vector<int>>& ans) {

        if(temp.size()==k) {
            if(n==0) {
                ans.push_back(temp);
                return;
            }
        }
    
        for(int i=idx;i<=9;i++) {
            if(i>n) break;
            temp.push_back(i);
            solve(i+1,k,n-i,temp,ans);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int> temp;
        solve(1,k,n,temp,ans);

        return ans;
    }
};