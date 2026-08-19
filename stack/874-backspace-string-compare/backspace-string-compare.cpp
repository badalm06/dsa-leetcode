class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string res1 = "";
        string res2 = "";
        stack<char> st1;
        stack<char> st2;
        for(int i=0;i<s.length();i++) {
            if(s[i] == '#') {
                if(!st1.empty()){
                    st1.pop();
                }
                continue;
            }   
            st1.push(s[i]);
        }
        for(int i=0;i<t.length();i++) {
            if(t[i] == '#') {
                if(!st2.empty()){
                    st2.pop();
                }
                continue;
            }
            st2.push(t[i]);
        }
        while(!st1.empty()) {
            res1.push_back(st1.top());
            st1.pop();
        }
        while(!st2.empty()) {
            res2.push_back(st2.top());
            st2.pop();
        }
        if(res1 == res2) return true;
        return false;
    }
};