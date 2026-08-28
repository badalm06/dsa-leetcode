class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int> mp;
        int cnt = 0;
        for(int i=0;i<tasks.size();i++) mp[tasks[i]]++;
        for(auto i:mp) {
            char element = i.first;
            int cnt = i.second;
            pq.push({cnt,element});
        }
        while(!pq.empty()) {
            vector<pair<int,char>> ls;
            for(int i=0;i<=n;i++) {
                if(!pq.empty()) {
                    pair<int,char> p = pq.top();
                    pq.pop();;
                    p.first--;
                    if(p.first>0) ls.push_back(p);
                }
                cnt++;

                if(pq.empty() && ls.empty()) break;
            }
            for(auto p: ls) {
                pq.push(p);
            }
        }
        return cnt;
    }
};