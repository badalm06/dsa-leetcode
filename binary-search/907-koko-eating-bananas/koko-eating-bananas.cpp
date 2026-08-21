class Solution {
public:

    long long guessSpeed(vector<int>& piles, int h, int speed) {
        long long hrs = 0;
        for(int i=0;i<piles.size();i++) {
            hrs = hrs + piles[i]/speed;
            if(piles[i]%speed != 0) hrs++;
        }
        return hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(),piles.end());
        int res = -1;
        while(low<=high) {
            int mid = low + (high-low)/2;
            long long hrs = guessSpeed(piles,h,mid);

            if(hrs>h) low = mid+1;
            else{
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
};