class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        bool insert = false;
        int n = intervals.size();
        vector<vector<int>> res;
        for(int i=0;i<n;i++) {
            if(insert == false && intervals[i][0]>=newInterval[0]){
                res.push_back(newInterval);
                insert = true;
            }
            res.push_back(intervals[i]);
        }
        if(insert == false) res.push_back(newInterval);
        int s1 = res[0][0];
        int e1 = res[0][1];
        vector<vector<int>> ans;


        for(int i=1;i<res.size();i++) {
            int s2 = res[i][0];
            int e2 = res[i][1];

            if(e1 >= s2) {
                s1 = s1;
                e1 = max(e1,e2);
                continue;
            }
            ans.push_back({s1,e1});
            s1 = s2;
            e1 = e2;
        }
        ans.push_back({s1,e1});
        return ans;
    }
};