class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int maxDiff = INT_MAX;
        int minSum = 0;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-1;i++){
            int sum = 0, diff = 0;
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                sum = nums[i]+nums[j]+nums[k];
                diff = abs(sum-target);
                while(diff<maxDiff){
                    maxDiff = diff;
                    minSum = sum;
                }
                if(sum==target) return sum;
                else if(sum>target) k--;
                else j++;
            }
        }
        return minSum;
    }
};