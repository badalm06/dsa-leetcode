class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> st;
        int left = 0;
        int sum = 0, maxSum = 0;

        for(int right=0;right<nums.size();right++){
            // Check for duplicate element
            while(st.count(nums[right])){
                sum -= nums[left];
                st.erase(nums[left]);
                left++;
            }
            st.insert(nums[right]);
            sum += nums[right];
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};