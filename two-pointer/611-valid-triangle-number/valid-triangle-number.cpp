class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 0;

        for(int i=nums.size()-1;i>=2;i--) {
            int left = 0, right = i-1;
            while(left<right) {
                // All elements between left and right
                // can form a valid triangle with nums[right] and nums[i]
                if(nums[left] + nums[right] > nums[i]){
                    cnt += right-left;
                    right--;
                }
                else left++;
            }
        }
        return cnt;
    }
};