class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int cnt = 0, n = intervals.size();
        int e1 = intervals[0][1];

        for(int i=1;i<n;i++) {
            int s2 = intervals[i][0], e2 = intervals[i][1];

            if(e1>s2) {
                cnt++;
                e1 = min(e1,e2);
            }
            else e1 = e2;
        }
        return cnt;
    }
};