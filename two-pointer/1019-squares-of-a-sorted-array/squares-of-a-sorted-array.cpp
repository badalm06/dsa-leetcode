class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for(int i=0;i<n;i++) {
            nums[i] = nums[i] * nums[i];
        }
        int head = 0;
        int tail = n-1;
        for(int i=result.size()-1;i>=0;--i) {
            if(nums[head]<nums[tail]) {
                result[i] = nums[tail];
                tail--;
            }
            else {
                result[i] = nums[head];
                head++;
            }
        }
        return result;
    }
};