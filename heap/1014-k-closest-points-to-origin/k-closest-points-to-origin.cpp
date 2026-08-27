class Solution {
public:

    int dist(vector<int>& point) {
        return point[0]*point[0] + point[1]*point[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;

        for(int i=0;i<k;i++) {
            int ans = dist(points[i]);
            pq.push({ans,i});
        }

        for(int i=k;i<points.size();i++) {
            int ans = dist(points[i]);
            if(ans < pq.top().first) {
                pq.pop();
                pq.push({ans,i});
            }
        }

        vector<vector<int>> res;
        while(!pq.empty()) {
            int index = pq.top().second;
            res.push_back(points[index]);
            pq.pop();
        }
        return res;
    }
};