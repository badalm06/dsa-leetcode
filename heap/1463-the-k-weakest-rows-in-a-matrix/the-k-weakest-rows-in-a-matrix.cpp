class Solution {
public:
    int soldiers(vector<int> arr) {
        int sd = 0;
        for(int i=0;i<arr.size();i++) {
            if(arr[i] == 1) sd++;
        }
        return sd;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>>pq;

        for(int i=0;i<k;i++) {
            int ans = soldiers(mat[i]);
            pq.push({ans,i});
        }

        for(int i=k;i<mat.size();i++) {
            int ans = soldiers(mat[i]);
            if(ans < pq.top().first ||
                    ans == pq.top().first && i < pq.top().second) {
                pq.pop();
                pq.push({ans,i});
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            int i = pq.top().second;
            res.push_back(i);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};