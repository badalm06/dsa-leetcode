class Solution {
public:
    void fun(int i, int n, int k, int cost, string temp, vector<string>& res){

        // Base condition (String complete) 
        if(i == n) {
            res.push_back(temp);
            return;
        }

        // Put 0
        temp.push_back('0');
        fun(i+1,n,k,cost,temp,res);
        temp.pop_back();

        // Put 1 & previous character should not be 1
        if((i==0 || temp[i-1] != '1') && cost+i <= k) {
            temp.push_back('1');
            fun(i+1,n,k,cost+i,temp,res);
            temp.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        string temp = "";
        vector<string> res;

        fun(0,n,k,0,temp,res);

        return res;
    }
};