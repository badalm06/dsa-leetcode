class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int left = 0;
        int maxLen = 1;
        int bitMask = 0;
        int n = nums.size();

        for(int right=0;right<n;right++) {
            while((bitMask & nums[right]) != 0){
                bitMask = bitMask ^ nums[left];
                left++;
            }
            bitMask = bitMask | nums[right];
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};