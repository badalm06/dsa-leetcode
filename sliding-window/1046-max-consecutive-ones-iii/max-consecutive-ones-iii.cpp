class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int maxLen = 0;
        int zeroCnt = 0;

        for(int right=0;right<nums.size();right++) {
            // Count total zero
            if(nums[right]==0) zeroCnt++;

            // Zero increase than k -> shrink
            while(zeroCnt > k) {
                if(nums[left]==0) zeroCnt--;
                left++;
            }
            // Update the max len
            maxLen = max(maxLen, right-left+1);
        }
        
        return maxLen;
    }
};