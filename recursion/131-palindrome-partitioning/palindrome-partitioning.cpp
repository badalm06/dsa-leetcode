class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        while(left<right) {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    void solve(string& s, int start, vector<string>& temp, vector<vector<string>>& ans) {

        // Entire string is partitioned
        if(start == s.length()) {
            ans.push_back(temp);
            return;
        }

        // Try every possible substring starting from start
        for(int i=start;i<s.length();i++) {

            // Only choose substring if it is palindrome
            if(isPalindrome(s,start,i)) {

                // Choose
                temp.push_back(s.substr(start, i-start+1));
                
                // Explore other options
                solve(s,i+1,temp,ans);

                // Backtracking
                temp.pop_back();

            }  
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s,0,temp,ans);

        return ans;

    }
};