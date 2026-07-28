class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> mp;
        int n = nums.size();
        long long maxSum = 0, curSum = 0;
        int left = 0;
        
        for(int right=0;right<=n-1;right++) {
            while(mp.count(nums[right]) || mp.size() == k) {
                mp.erase(nums[left]);
                curSum -= nums[left];
                left++;
            }
            mp.insert(nums[right]);
            curSum += nums[right];
            if(mp.size() == k) {
                maxSum = max(maxSum,curSum);
            }
        }
        return maxSum;
    }
};