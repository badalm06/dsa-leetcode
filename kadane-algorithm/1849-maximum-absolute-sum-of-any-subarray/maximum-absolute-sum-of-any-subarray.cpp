class Solution {
public:

    int maxSum(vector<int> nums) {
        int ans = nums[0];
        int best_ending = nums[0];

        for(int i=1;i<nums.size();i++) {
            int v1 = nums[i];
            int v2 = best_ending + nums[i];
            best_ending = max(v1,v2);
            ans = max(ans,best_ending);
        }
        return ans;
    }

    int minSum(vector<int> nums) {
        int ans = nums[0];
        int best_ending = nums[0];

        for(int i=1;i<nums.size();i++) {
            int v1 = nums[i];
            int v2 = best_ending + nums[i];
            best_ending = min(v1,v2);
            ans = min(ans,best_ending);
        }
        return ans;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int maxi = maxSum(nums);
        int mini = minSum(nums);
        return max(abs(maxi), abs(mini));
    }
};