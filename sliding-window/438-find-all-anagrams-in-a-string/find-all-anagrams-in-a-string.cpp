class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> s1(26,0);
        vector<int> p1(26,0);
        vector<int> ans;
        int left = 0;

        for(char ch:p) {
            p1[ch-'a']++;
        }
        for(int right=0;right<s.size();right++){
            s1[s[right]-'a']++;

            if(right-left+1 > p.size()){
                s1[s[left]-'a']--;
                left++;
            }
            if(s1 == p1) ans.push_back(left);
        }
        return ans;
    }
};