class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i=0,j=0, n = firstList.size(), m = secondList.size();

        while(i<n && j<m) {
            int s1 = firstList[i][0], e1 = firstList[i][1];
            int s2 = secondList[j][0], e2 = secondList[j][1];

            if(s1<=s2) {
                if(e1>=s2) {
                    int s = max(s1,s2);
                    int e = min(e1,e2);
                    res.push_back({s,e});
                }
            }
            else {         // s1>=s2
                if(e2>=s1) {
                    int s = max(s1,s2);
                    int e = min(e1,e2);
                    res.push_back({s,e});
                }
            }
            if(e1<=e2) i++;
            else j++;
        }
        return res;
    }
};