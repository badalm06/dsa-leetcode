class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> p(n);
        for(int i=0;i<n;i++) {
            p[i] = {capital[i],profits[i]};
        }
        sort(p.begin(),p.end());
        priority_queue<int>pq;
        int i = 0;

        while(k--) {
            while(i < n && p[i].first <= w) {
                pq.push(p[i].second);
                i++;
            }
            if(pq.empty()) break;
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};