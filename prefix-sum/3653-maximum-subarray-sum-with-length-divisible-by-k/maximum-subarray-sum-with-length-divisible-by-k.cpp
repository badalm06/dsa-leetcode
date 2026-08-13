class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        long long ans = LLONG_MIN;
        unordered_map<int,long long> f;
        f[0] = 0;

        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
            int rem = (i+1) % k;

            // Same remainder means length is divisible by k
            if(f.find(rem) != f.end()) ans = max(ans, sum - f[rem]);

            // Keep the smallest prefix sum
            if(f.find(rem) == f.end()){
                f[rem] = sum;
            }
            else {
                f[rem] = min(f[rem], sum);
            }
        }
        return ans;
    }
};