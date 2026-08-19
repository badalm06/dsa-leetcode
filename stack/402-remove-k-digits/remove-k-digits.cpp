class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        string res = "";

        if(num.length()<=k) return "0";
        if(k==0) return num;
        st.push(num[0]);

        for(int i=1;i<num.length();i++) {
            while(k>0 && !st.empty() && st.top()>num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
            if(st.size() == 1 && num[i] == '0') st.pop();
        }
        while(k && !st.empty()){
            k--;
            st.pop();
        }
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        if(res.length() == 0) return "0";
        return res;
    }
};