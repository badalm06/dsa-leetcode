class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;
        int cnt = 0, k = 1;

        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }
        for(auto c: freq) {
            int f = c.second;
            if(f%2 == 0) {
                cnt += f;
            }
            else {
                cnt += f-1;
                if(k>0) {
                    cnt+= 1;
                    k--;
                }
            }
        }
        return cnt;
    }
};