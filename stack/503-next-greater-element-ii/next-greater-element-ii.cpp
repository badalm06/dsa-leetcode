class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,-1);
        stack<int> st;

        for(int i=2*n-2;i>=0;i--) {
            int index = i%n;
            while(!st.empty() && st.top() <= nums[index]) {
                st.pop();
            }
            if(i<n) {
                if(!st.empty()) res[index] = st.top();
            }
            st.push(nums[index]);
        }
        return res;
    }
};