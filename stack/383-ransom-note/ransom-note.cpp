class Solution {
public:
    bool check(unordered_map<char,int> f1, unordered_map<char,int> f2) {
        for(auto i: f1){
            char c = i.first;
            int fNeed = i.second;
            int fHave = f2[c];
            if(fNeed>fHave) return false;
        }
        return true;
    }

    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> f1;
        unordered_map<char,int> f2;

        for(int i=0;i<ransomNote.length();i++) f1[ransomNote[i]]++;
        for(int i=0;i<magazine.length();i++) f2[magazine[i]]++;

        return check(f1,f2);
    }
};