class Solution {
public:
    void solve(string digit, string output, int idx, vector<string>& ans, string mapping[]) {
        if(idx>=digit.length()) {
            ans.push_back(output);
            return;
        }
        int num = digit[idx] - '0';
        string choice = mapping[num];

        for(int j=0;j<choice.length();j++) {
            output.push_back(choice[j]);
            solve(digit,output,idx+1,ans,mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output = "";
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno",
                            "pqrs", "tuv", "wxyz"};

        solve(digits,output,0,ans,mapping);
        return ans; 
    }
};