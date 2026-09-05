class Solution {
public:
    void solve(vector<int>& candidates, int n, int idx, vector<int>& temp, int sum, vector<vector<int>>& ans, int target) {
        if(idx==n) {
            if(sum==target) ans.push_back(temp);
            return;
        }

        // Choice 1: Don't want to add
        solve(candidates,n,idx+1,temp,sum,ans,target);

        // Choice 2: Want to add
        if(candidates[idx]+sum <= target) {
            temp.push_back(candidates[idx]);
            sum += candidates[idx];
            solve(candidates,n,idx,temp,sum,ans,target);
            temp.pop_back();
            sum -= candidates[idx];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();

        solve(candidates,n,0,temp,0,ans,target);

        return ans;
    }
};