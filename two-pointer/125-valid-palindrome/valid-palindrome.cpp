class Solution {
public:

    string removeSpecialChar(string &s) {
        string updateString = "";

        for(char ch:s) {
            if(ch>='a' && ch<='z') updateString += ch;
            else if(ch>='A' && ch<='Z') updateString += (ch+32);
            else if(ch>='0' && ch<='9') updateString += ch;
        }
        return updateString;
    }

    bool isPalindrome(string s) {
        string newString = removeSpecialChar(s);
        int n = newString.size();
        int left = 0;
        int right = n-1;

        while(left<right) {
            if(newString[left] != newString[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};