class Solution {
public:
    int ladderLength(string b, string e, vector<string>& word) {
        int n = word.size();
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++) mp[word[i]] = 1;
        if(mp.find(b) == mp.end()) mp[b] = 1;
        if(mp.find(e) == mp.end()) return 0;
        queue<pair<string,int>> q;
        q.push({b,1});
        mp.erase(b);
        while(!q.empty()) {
            pair<string,int> p = q.front();
            q.pop();
            string s = p.first;
            int val = p.second;
            if(s == e) return val;
            for(int i=0;i<s.size();i++) {
                char c = s[i];
                for(int j=97;j<=122;j++) {
                    if(c == j) continue;
                    s[i] = j;
                    if(mp.find(s) != mp.end()) {
                        q.push({s,val+1});
                        mp.erase(s);
                    }
                }
                s[i] = c;
            }
        }
        return 0;
    }
};