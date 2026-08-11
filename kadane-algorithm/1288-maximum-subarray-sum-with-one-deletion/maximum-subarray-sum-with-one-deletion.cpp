class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        // Best sum without deleting
        int noPower = arr[0];

        // Best sum after deleting one element
        int power = 0;

        // Overall maximum
        int ans = arr[0];        
        for(int i=1;i<n;i++) {
            int v1 = arr[i];   // Start new subarray
            int v2 = noPower + arr[i];   // Extend without deletion
            int v3 = power + arr[i];   // Extend after one deletion
            int v4 = noPower;   // Delete current element
            ans = max(ans, max(max(v1, v2), max(v3, v4)));  // Takes the best one
            noPower = max(v1,v2);   // Update no-deletion state
            power = max(v3,v4);   // Update one-deletion state
        }
        return ans;
    }
};