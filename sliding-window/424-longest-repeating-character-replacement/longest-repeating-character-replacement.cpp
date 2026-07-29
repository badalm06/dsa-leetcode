class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int> st;
        int left = 0, maxLen = 0, maxFreq = 0;

        for(int right=0;right<n;right++){
            //Add Current Characters
            st[s[right]]++;

            //Update max freq at current window
            maxFreq = max(maxFreq, st[s[right]]);

            // shrink if more than k replacement needed
            while((right-left+1)-maxFreq > k){
                st[s[left]]--;
                left++;
            }
            // update answer
            maxLen = max(maxLen,right-left+1);
        }
        return maxLen;
    }
};