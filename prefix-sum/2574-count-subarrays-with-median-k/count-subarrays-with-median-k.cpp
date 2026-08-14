class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> cnt;
        cnt[0] = 1;
        int balance = 0;
        int ans = 0;
        bool includeK = false;

        for(int i=0;i<n;i++) {
            if(nums[i] > k) balance++;
            else if(nums[i] < k) balance--;
            else  {      // nums[i] == k
                includeK = true;
            }
            if(includeK) {
                ans += cnt[balance] + cnt[balance-1];
            }     
            else {
                cnt[balance]++;
            }
        }
        return ans;
    }
};