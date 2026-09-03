class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        long long sum = 0;
        for(auto gift:gifts) {
            pq.push(gift);
        }

        while(k>0) {
            int x = pq.top();
            pq.pop();
            int y = sqrt(x);
            pq.push(y);
            k--;
        }
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
        return sum;
    }
};