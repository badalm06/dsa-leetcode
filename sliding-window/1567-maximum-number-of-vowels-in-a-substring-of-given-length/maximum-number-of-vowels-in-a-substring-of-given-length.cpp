class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_map<char,int> st;
        int left = 0;
        int vovCnt = 0;
        int maxCnt = 0;

        for(int right=0;right<s.size();right++) {
            st[s[right]]++;
            if(s[right]=='a' || s[right]=='e' || s[right]=='i' || 
            s[right]=='o' || s[right]=='u') vovCnt++;

            while(right-left+1>k){
                st[s[left]]--;
                if(s[left]=='a' || s[left]=='e' || s[left]=='i' || 
                s[left]=='o' || s[left]=='u') vovCnt--;
                left++;
            }
            if(right-left+1==k){
                maxCnt = max(maxCnt,vovCnt);
            }
        }
        return maxCnt;
    }
};