class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++) {
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto i:mp) {
            char element = i.first;
            int freq = i.second;
            pq.push({freq,element});
        }
        string res = "";

        while(!pq.empty()) {
            int freq = pq.top().first;
            char element = pq.top().second;
            pq.pop();
            while(freq--) res.push_back(element);
        }
        return res;
    }
};