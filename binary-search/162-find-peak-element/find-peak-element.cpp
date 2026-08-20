class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // Only one element
        if(nums.size() == 1) return 0;

        // Check first element
        if(nums[0] > nums[1])
            return 0;

        // Check last element
        if(nums[nums.size()-1] > nums[nums.size()-2])
            return nums.size()-1;
        int low = 1, high = nums.size()-2;

        while(low<=high) {
            int mid = low + (high-low)/2;
            if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(nums[mid-1] < nums[mid]) low = mid+1;
            else high = mid - 1;
        }
        return -1;
    }
};