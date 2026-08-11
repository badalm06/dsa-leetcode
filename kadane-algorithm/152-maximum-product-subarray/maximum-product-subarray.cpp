class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Defining 2 endings
        int min_ending = nums[0], max_ending = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++) {
            int v1 = nums[i];
            int v2 = min_ending * nums[i];
            int v3 = max_ending * nums[i];

            min_ending = min(v1, min(v2,v3)); // keeping record of min number (negative)
            max_ending = max(v1, max(v2,v3)); // keeping record of max number
            
            ans = max(ans, max(max_ending,min_ending)); // checking which one is greater
        }
        return ans;
    }
};