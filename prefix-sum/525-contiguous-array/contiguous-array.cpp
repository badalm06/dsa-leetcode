class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zero = 0, one = 0, ans = 0;
        unordered_map<int,int> f;

        for(int i=0;i<nums.size();i++) {
            if(nums[i] == 0) zero++;
            else one++;

            int diff = zero - one;

            if(diff == 0) {
                ans = max(ans, i+1);
                continue;
            }

            // This line says ki diff is not present in f, so add it
            if(f.find(diff) == f.end()) f[diff] = i; 
            else{
                ans = max(ans, i - f[diff]);
            }
        }
        return ans;
    }
};