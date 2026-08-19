class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mp;
        for(int i=0;i<text.length();i++) {
            mp[text[i]]++;
        }

        unordered_map<char,int> mpp2;
            mpp2['b'] = 1;
            mpp2['a'] = 1;
            mpp2['l'] = 2;
            mpp2['o'] = 2;
            mpp2['n'] = 1;
        
        int res = INT_MAX;
        for(auto i:mpp2) {
            char c = i.first;
            int fmpp2 = i.second;
            int fmp = mp[c];
            int times = fmp/fmpp2;
            res = min(res,times);
        }
        return res;
    }
};