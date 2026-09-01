class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int num:nums) {
            pq.push(num);
            if(pq.size()>2) pq.pop();
        }

        int a = pq.top()-1;
        pq.pop();
        int b = pq.top()-1;
        pq.pop();
        return (a)*(b); 
    }
};