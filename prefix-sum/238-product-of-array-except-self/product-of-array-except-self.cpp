class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        vector<int> output(n);
        output[0] = 1;
        for(int i=1;i<n;i++) {
            output[i] = output[i-1] * nums[i-1];
        }

        for(int i=n-1;i>=0;i--) {
            output[i] *= product;
            product *= nums[i];
        }
        return output;
    }
};