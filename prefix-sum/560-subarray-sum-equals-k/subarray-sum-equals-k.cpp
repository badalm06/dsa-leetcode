class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;    // Current prefix sum
        int res = 0;    // Total number of valid subarrays
        unordered_map<int,int> f;
        // Helps count subarrays starting from index 0
        f[0] = 1;

        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            int ques = sum - k;      // We need an old prefix sum = sum - k
            int freq = f[ques];      // this tells how many times have we seen this prefix sum?
            res += freq;     // Each occurrence gives one valid subarray
            f[sum]++;        // Store current prefix sum for future subarrays
        }
        return res;
    }
};