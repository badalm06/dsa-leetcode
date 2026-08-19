class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> res;
        int n = asteroids.size();

        for(int i=0;i<n;i++) {
            while(!st.empty() && st.top()>0 && asteroids[i]<0) {
                if(st.top() > -asteroids[i]) {
                    asteroids[i] = 0;
                    break;
                }
                else if(st.top() == -asteroids[i]) {
                    st.pop();
                    asteroids[i] = 0;
                    break;
                }
                else st.pop();
            }
            if(asteroids[i] != 0) st.push(asteroids[i]);
        }

        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(),res.end());
        return res;
    }
};