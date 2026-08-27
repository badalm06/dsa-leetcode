class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        string res = "";
        int seat = 0;
        for(int i=0;i<s.length();i++) {
            mp[s[i]]++;
        }
        for(auto i:mp) {
            char element = i.first;
            int count = i.second;
            pq.push({count,element}); 
        }

        while(!pq.empty()) {
        pair<int,char> p = pq.top();
            pq.pop();
            if(seat == 0 || res[seat-1] != p.second) {
                res.push_back(p.second);
                seat++;
                p.first--;
                if(p.first>0) pq.push(p);
            }
            else {
                if(pq.empty()) return "";
                pair<int,char> p2 = pq.top();
                pq.pop();
                res.push_back(p2.second);
                seat++;
                p2.first--;
                if(p2.first>0) pq.push(p2);
                pq.push(p);
            }
        }
        return res;
    }
};