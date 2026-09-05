class Solution {
public:
    void fun(int open, int close, int n, string temp, vector<string>& res) {
        // Complete valid paranthesis
        if(open==n && close==n) res.push_back(temp);

        // Add open bracket
        if(open<n) {
            temp.push_back('(');
            fun(open+1,close,n,temp,res);
            temp.pop_back();
        }

        // Add close bracket
        if(close<open) {
            temp.push_back(')');
            fun(open,close+1,n,temp,res);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int open = 0, close = 0;
        string temp = "";
        vector<string> res;
        fun(open,close,n,temp,res);

        return res;
    }
};