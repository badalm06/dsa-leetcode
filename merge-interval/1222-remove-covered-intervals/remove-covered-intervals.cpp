class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1]>b[1];
        return a[0]<b[0];
        });

        int n = intervals.size();
        int cnt = 0;
        int s1 = intervals[0][0], e1 = intervals[0][1];

        for(int i=1;i<n;i++) {
            int s2 = intervals[i][0], e2 = intervals[i][1];

            if(e2<=e1) {
                cnt++;
            }
            else e1=e2;
        }
        return n-cnt;
    }
};