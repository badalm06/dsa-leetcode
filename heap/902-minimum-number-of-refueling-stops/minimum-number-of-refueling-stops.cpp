class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int max_reach = startFuel;
        int cnt = 0, index = 0;
        priority_queue<int>pq;

        while(max_reach<target) {
            while(index<stations.size() && stations[index][0] <= max_reach) {
                pq.push(stations[index][1]);
                index++;
            }
            if(pq.empty()) return -1;
            max_reach += pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};