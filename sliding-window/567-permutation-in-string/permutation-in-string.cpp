class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> f1(26,0);
        vector<int> f2(26,0);
        int left = 0;

        for(char ch:s1) {
            f1[ch-'a']++;
        }
        for(int right=0;right<s2.size();right++){
            // Add current character
            f2[s2[right]-'a']++;

            // Keep window size equal to length of s1
            if(right-left+1 > s1.size()){
                f2[s2[left]-'a']--;
                left++;
            }
            if(f1 == f2) return true;
        }
        return false;
    }
};