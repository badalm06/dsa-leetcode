class Solution {
public:
    int possible(vector<int>& bloomDay, int m, int k, int mid) {
        int cnt = 0, cntBq = 0;
        for(int i=0;i<bloomDay.size();i++) {
            if(bloomDay[i] <= mid) cnt++;
            else{
                cntBq += cnt/k;
                cnt = 0;
            }
        }
        cntBq += cnt/k;
        return cntBq;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        int res = -1;

        while(low<=high) {
            int mid = low + (high-low)/2;
            int cntBq = possible(bloomDay,m,k,mid);
            if(cntBq >= m) {
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return res;
    }
};