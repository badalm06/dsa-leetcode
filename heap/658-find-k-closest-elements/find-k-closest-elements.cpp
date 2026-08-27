class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>pq;

        for(int i=0;i<k;i++) {
            int ans = abs(x-arr[i]);
            pq.push({ans,i});
        }

        for(int i=k;i<arr.size();i++) {
            int ans = abs(x-arr[i]);
            if(ans < pq.top().first) {
                pq.pop();
                pq.push({ans,i});
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            int i = pq.top().second;
            res.push_back(arr[i]);
            pq.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};