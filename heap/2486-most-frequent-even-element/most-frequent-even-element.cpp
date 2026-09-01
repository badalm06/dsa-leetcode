class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++) {
            mp[nums[i]]++;
        }
        int ans = -1, max = -1;
        for(auto i:mp) {
            if(i.first%2==0 && i.second>max) {
                max = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};