class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long curSum = 0;
        for(int i=0;i<k;i++){
            curSum += nums[i];
        }
            long long maxSum = curSum;
            for(int i=k;i<nums.size();i++) {
                curSum += nums[i];
                curSum -= nums[i-k];
                maxSum = max(curSum,maxSum);
            }
            return (double)maxSum/k;
    }
};