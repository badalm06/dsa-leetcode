class Solution {
public:
    void solve(int i, int n, string& temp, vector<string>& ans) {
        if(i==n) {
            ans.push_back(temp);
            return;
        }

        // Choice 1: Add 1
        temp.push_back('1');
        solve(i+1,n,temp,ans);
        temp.pop_back();

        // Choice 2: Add 0 
        if(i==0 || temp[i-1] != '0') {
            temp.push_back('0');
            solve(i+1,n,temp,ans);
            temp.pop_back();
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp = "";

        solve(0,n,temp,ans);

        return ans;
    }
};