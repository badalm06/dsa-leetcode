class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<pair<int,int>> arr;            // {start,original index}

        for(int i=0;i<n;i++) {
            arr.push_back({intervals[i][0],i});
        }

        sort(arr.begin(),arr.end());
        vector<int> res(n);

        for(int i=0;i<n;i++) {
            int target = intervals[i][1];
            int low = 0, high = n-1, ans = -1;

            while(low<=high) {
                int mid = low + (high-low)/2;
                if(arr[mid].first >= target) {
                    ans = mid;
                    high = mid-1;
                }
                else low = mid+1;
            }
            if(ans == -1) res[i] = -1;
            else res[i] = arr[ans].second;
        }
        return res;
    }
};