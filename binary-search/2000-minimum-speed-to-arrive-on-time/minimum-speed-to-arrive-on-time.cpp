class Solution {
public:
    double minSpeed(vector<int>& dist, double hour, int mid) {
        double hrs = 0;
        for(int i=0;i<dist.size()-1;i++) {
            hrs += dist[i]/mid;
            if(dist[i]%mid != 0) hrs++;
        }
        hrs += (double)dist.back() / mid;
        return hrs;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e7;
        int res = -1;

        while(low<=high) {
            int mid = low + (high-low)/2;
            double hrs = minSpeed(dist,hour, mid);
            if(hrs>hour) low = mid+1;
            else {
                res = mid;
                high = mid-1;
            }
        }
        return res;
    }
};