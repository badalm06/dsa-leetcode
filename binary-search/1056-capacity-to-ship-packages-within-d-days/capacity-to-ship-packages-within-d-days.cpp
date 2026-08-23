class Solution {
public: 
    bool checkDays(vector<int>& weights, int days, int mid) {
        int sum = 0, n = weights.size(), cnt = 1;
        for(int i=0;i<n;i++) {
            if(sum + weights[i] > mid) {
                cnt++;
                sum = weights[i];
            }
            else {
                sum += weights[i];
            }
        }
        if(cnt <= days) return true;
        return false;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low= *max_element(weights.begin(),weights.end());
        int high= accumulate(weights.begin(),weights.end(),0);
        int res = 0;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(checkDays(weights,days,mid)) {
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return res;
    }
};