class Solution {
public:
    bool checkSum(vector<int>& nums, int k, int mid) {
        int sum = 0, cnt = 1;
        for(int i=0;i<nums.size();i++) {
            if(sum + nums[i] > mid) {
                cnt++;
                sum = nums[i];
            }
            else sum += nums[i];
        }
        if(cnt<=k) return true;
        return false;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);
        int res = 0;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(checkSum(nums,k,mid)) {
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return res;
    }
};