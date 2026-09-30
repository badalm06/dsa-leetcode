class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> a(n);
        for(int i=0;i<times.size();i++) {
            int s = times[i][0];
            int d = times[i][1];
            int w = times[i][2];
            a[s-1].push_back({d-1,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(n,INT_MAX);
        dist[k-1] = 0;
        pq.push({0,k-1});
        while(!pq.empty()) {
            pair<int,int> p = pq.top();
            pq.pop();
            int dis = p.first;
            int node = p.second;
            if(dis> dist[node]) continue;
            for(int j=0;j<a[node].size();j++) {
                int neigh = a[node][j].first;
                int wt = a[node][j].second;
                if(dis+wt < dist[neigh]) {
                    dist[neigh] = dis + wt;
                    pq.push({dis+wt, neigh});
                }
            }
        }
        int maxi = 0;
        for(int i=0;i<dist.size();i++) {
            maxi = max(maxi, dist[i]);
            if(maxi == INT_MAX) return -1;
        }
        return maxi;
    }
};