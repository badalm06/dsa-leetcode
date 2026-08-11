class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0];
        int minSum = nums[0];
        int currMaxSum = nums[0];
        int currMinSum = nums[0];
        int totalSum = nums[0];

        for(int i=1;i<nums.size();i++) {
            // Apply Kadane's for max sum
            currMaxSum = max(currMaxSum + nums[i], nums[i]);
            maxSum = max(maxSum, currMaxSum);

            // apply Kadane's for min sum
            currMinSum = min(currMinSum + nums[i], nums[i]);
            minSum = min(minSum, currMinSum);

            totalSum += nums[i];
        }
        int circularSum = totalSum - minSum;

        // Edge case: If all numbers are negative, then we need to return the max negative number
        if(circularSum == 0) return maxSum;

        return max(maxSum, circularSum);

    }
};