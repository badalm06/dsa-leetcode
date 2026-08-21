class Solution {
public:
    long long guessCandies(vector<int>& candies, int mid) {
        long long children = 0;
        for(int i=0;i<candies.size();i++) {
            children += candies[i]/mid;
        }
        return children;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = *max_element(candies.begin(),candies.end());
        int res = 0;

        while(low<=high) {
            int mid = low + (high-low)/2;
            long long children = guessCandies(candies,mid);

            if(children >= k) {
                res = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return res;
    }
};