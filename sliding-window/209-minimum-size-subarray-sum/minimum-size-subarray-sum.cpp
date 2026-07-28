class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int minLen = INT_MAX;
        int ans = 0;
        for(int right=0;right<n;right++) {
            ans += nums[right];
            while(ans >= target){
                minLen = min(minLen, right-left+1);
                ans -= nums[left];
                left++;
            }
        }
        return (minLen==INT_MAX) ? 0 : minLen;
    }
};