class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff[1001] = {};

        for(auto trip:trips) {
            int passengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            diff[from] += passengers;
            diff[to] -= passengers;
        }
        int cnt = 0;
        for(int i=0;i<1000;i++) {
            cnt += diff[i];

            if(cnt>capacity) return false;
        }
        return true;
    }
};