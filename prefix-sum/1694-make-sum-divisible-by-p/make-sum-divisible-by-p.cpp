class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = 0;
        for(int i=0;i<nums.size();i++) {
            sum += nums[i];
        }
        int rem = sum % p;
        if(rem == 0) return 0;
        int prefixSum = 0;
        unordered_map<int,int> f;
        f[0] = -1;
        long prefix = 0;
        int ans = nums.size();
        for(int i=0;i<nums.size();i++) {
            prefix += nums[i];
            int currRem = prefix % p;
            int prevRem = (currRem - rem + p) % p;

            if(f.find(prevRem) != f.end()) {
                ans = min(ans, i - f[prevRem]);
            }
            f[currRem] = i;
        }
        if(ans == nums.size()) return -1;
        return ans;
    }
};